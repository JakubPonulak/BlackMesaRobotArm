#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_PWMServoDriver.h>

#define servoMin 75
#define servoMax 535
#define handMin 305
#define handMax 415

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  // REMEMBER TO SET VOLTAGE TO 6.00 V

int hand = 11;
int wrist = 10;
int elbow = 9;  //Assign Motors to pins on Servo Driver Board
int shoulder = 7;
int base = 5;

int pos1 = 305;  // hand
int pos2 = 305;  // wrist
int pos3 = 305;  // elbow                // 305 is intermediate value, "middle" of servo
int pos4 = 305;  // shoulder
int pos5 = 305;  // base

const int step = 5;  // step for servo movement per keypress

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // set frequency to 50 Hz
  EEPROM.get(0, pos1);
  EEPROM.get(2, pos2);
  EEPROM.get(4, pos3);
  EEPROM.get(6, pos4);
  EEPROM.get(8, pos5);
  pwm.setPWM(hand, 0, pos1);
  pwm.setPWM(wrist, 0, pos2);
  pwm.setPWM(elbow, 0, pos3);
  pwm.setPWM(shoulder, 0, pos4);
  pwm.setPWM(base, 0, pos5);
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    // hand movement
    if (cmd == '4') {
      pos1 += step;
      if (pos1 > handMax) pos1 = handMax;
      pwm.setPWM(hand, 0, pos1);
      Serial.print("Hand opening. Position: ");
      Serial.println(pos1);
    } else if (cmd == '5') {
      pos1 -= step;
      if (pos1 < handMin) pos1 = handMin;
      pwm.setPWM(hand, 0, pos1);
      Serial.print("Hand closing. Position: ");
      Serial.println(pos1);
    }
    // wrist movement
    else if (cmd == '6') {
      pos2 += step;
      if (pos2 > servoMax - 35) pos2 = servoMax - 35;
      pwm.setPWM(wrist, 0, pos2);
      Serial.print("Wrist moving up. Position: ");
      Serial.println(pos2);
    } else if (cmd == '7') {
      pos2 -= step;
      if (pos2 < servoMin + 35) pos2 = servoMin + 35;
      pwm.setPWM(wrist, 0, pos2);
      Serial.print("Wrist moving down. Position: ");
      Serial.println(pos2);
    }
    // elbow movement
    else if (cmd == '8') {
      pos3 += step;
      if (pos3 > servoMax) pos3 = servoMax;
      pwm.setPWM(elbow, 0, pos3);
      Serial.print("Elbow moving down. Position: ");
      Serial.println(pos3);
    } else if (cmd == '9') {
      pos3 -= step;
      if (pos3 < servoMin) pos3 = servoMin;
      pwm.setPWM(elbow, 0, pos3);
      Serial.print("Elbow moving up. Position: ");
      Serial.println(pos3);
    }
    // shoulder movement
    else if (cmd == '3') {
      pos4 += step;
      if (pos4 > servoMax) pos4 = servoMax;
      pwm.setPWM(shoulder, 0, pos4);
      Serial.print("Shoulder moving down. Position: ");
      Serial.println(pos4);
    } else if (cmd == '2') {
      pos4 -= step;
      if (pos4 < servoMin) pos4 = servoMin;
      pwm.setPWM(shoulder, 0, pos4);
      Serial.print("Shoulder moving up. Position: ");
      Serial.println(pos4);
    }
    // base movement
    else if (cmd == '0') {
      pos5 += step;
      if (pos5 > servoMax) pos5 = servoMax;
      pwm.setPWM(base, 0, pos5);
      Serial.print("Base moving left. Position: ");
      Serial.println(pos5);
    } else if (cmd == '1') {
      pos5 -= step;
      if (pos5 < servoMin) pos5 = servoMin;
      pwm.setPWM(base, 0, pos5);
      Serial.print("Base moving right. Position: ");
      Serial.println(pos5);
    }
    // saving location
    else if (cmd == 's') {
      EEPROM.put(0, pos1);
      EEPROM.put(2, pos2);
      EEPROM.put(4, pos3);
      EEPROM.put(6, pos4);
      EEPROM.put(8, pos5);
    }
  }
}
