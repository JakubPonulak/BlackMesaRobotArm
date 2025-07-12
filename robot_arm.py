import serial
import keyboard
import time
import os

arduino = serial.Serial('COM10', 9600)
# Replace COM10 with the port the HC05 is using

keys = ['a','d','w','s','space','ctrl','q','e','z','c']
# List of keys that correspond to commands

print("Ready to Recieve Commands:")
print("Commands:")
print("Gripper Open/Close: Space/Ctrl")
print("Wrist Up/Down: Q/E")
print("Elbow Up/Down: Z/C")
print("Shoulder Up/Down: W/S")
print("Base Left/Right: A/D")

while True:
    if arduino.in_waiting > 0:
        line = arduino.readline().decode('utf-8').rstrip()
        if line:
            print("From Arduino:", line)

    for i, key in enumerate(keys):
            if keyboard.is_pressed(key):
                arduino.write(f"b{i}".encode())
                time.sleep(0.001)
                
    if keyboard.is_pressed('`'):
        print("Stopping script...")
        arduino.write("s".encode())
        time.sleep(1)
        os.system('cls')
        break    
