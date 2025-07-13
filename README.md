<p align="center">
  <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/bm2.jpg" width="200" />
</p>

# Black Mesa Robot Arm
This is the GitHub repository for the Black Mesa Hazardeous Material Manipulation Device, a small robot arm powered by an Arduino Uno microcontroller, which can be operated through keyboard inputs via Bluetooth. The purpose of this project was to utilize my knowledge of mechanical, electrical, and software engineering into a working device with a practical purpose.

<p align="center">
  <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/robot_main.png" width="500" />
</p>

The name of the robot, along with its design and decorative elements, come from the iconic video game "Half-Life", which was groundbreaking at the time of its release and has heavily impacted the FPS genre. Specifically, the robot name and design are a reference to the Black Mesa Research Facility, a fictional laboratory complex and research center which is the setting of the game. This game is a personal favorite of mine, and its aesthetic and theme fit perfectly into this project.

## Initial Design
I was first inspired to make this robot arm after watching [this video](https://www.youtube.com/watch?v=5toNqaGsGYs&list=PLPR41m1Dqd8Jqq6F-DI4-8zMKgnmrkHdz) by Build Some Stuff on YouTube. While the robot in the video was interesting on its own, I was determined to make my own version, both in terms of design and how it was to be controlled / manipulated. I first got to work in Blender, a 3D modelling program that I have been using since high school, and I created a rough "sketch" of what I wanted my robot arm to look like:

<p align="center">
  <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/s1.png" width="500" />
</p>

After coming up with this design, I switched over to CAD modeling in SOLIDWORKS, which is better suited for creating real-life components, and with which I have much more experience. Based on dimensions given in the YouTube video's description, I was able to model each individual part of the robot and combine them into a complete SOLIDWORKS assembly, simulating the look and behavior of the robot arm. By importing additional pre-made parts such as Servo Motors and the Arduino Uno, I was able to ensure that the internal components of the robot would fit inside it, and that there were no interferences between components. 

DISCLAIMER: The assembly file that I have uploaded to this repository is a minimal version that can be built using only the parts I created. Please contact me if you would like a complete version that includes these additional parts.

<p align="center">
  <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/robot_design.png" width="800" />
</p>

Using SOLIDWORKS also allowed me to run an FEA simulation of the robot arm, specifically to see how the arm would react to a 300 gram object being held in place by the grippers, which is the maximum weight that I envisioned the robot would be able to carry with its limited grasp. I ran this simulation multiple times, varying the orientation of the arm in each run. The most critical iteration occurred when the arm was fully outstretched to the side, as this configuration exerted the greatest moment on the base.

<p align="center">
  <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/static_study.png" width="800" />
</p>

Once the design was complete, I uploaded my STP files to Craftcloud, an online 3D printing service that matches customers to manufacturers across the globe. While I waited for my parts to be printed in PLA and shipped to my home, I got to work on the software needed to run this robot arm.

## Writing Code in Arduino Language and Python
I had worked with Arduino boards and the Arduino language (a derivative of C++) in the past, and so I was already familiar with writing code for my microcontroller board. However, I had never worked with servo motors before, and so I had to learn about operating and manipulating them, which is where the Adafruit PWM Servo Driver Library comes in. This library allows easy manipulation of servo motors that are connected to the Arduino via a Servo Motor Driver board, which in my case was the PCA9685. I also utilized the EEPROM (Electrically Erasable Programmable Read-Only Memory) library, which allows the program to save data to the Arduino’s built-in non-volatile memory. This makes it possible to store servo positions or settings that are automatically restored when the robot is powered back on.

Initially, I thought that I would only need to write code in the Arduino IDE, but I soon realized that it did not allow for the type of user input I wanted. My initial plan was to control the robot using individual keystrokes like "A", "D", or "Space". However, the Arduino IDE lacked built-in functionality for detecting keyboard input. To work around this, I decided to use Python, which allowed me to use the keyboard library, which allows scripts to detect and respond to keyboard input in real-time. The script reads the user's input on the keyboard, and sends a corresponding signal (a single integer or character) to the Arduino via the appropriate serial port. On the Arduino side, the uploaded code reads the incoming serial data and interprets the command by executing a predefined action, mainly changing the position of a specific servo motor. This setup allows real-time control of the robot arm through simple keystrokes on the keyboard.

## Final Assembly and Wiring
Once all of my 3D-printed parts and mechanical / eletrical components arrived in the mail, I was ready to assemble the robot arm. Although the robot was designed with precision in SOLIDWORKS, the physical parts required several adjustments during assembly due to manufacturing imperfections. This included sanding down certain surfaces for a better fit, enlarging holes to properly accommodate screw diameters, and filing edges to improve joint mobility and rotation smoothness.

There were also some design flaws that I had failed to notice when first designing the parts for the robot arm. For example, some of the parts of the robot have cutouts for the servo motor wires, and I had underestimated how much space these wires would take up, especially at the base of the arm, where 4 sets of wires had to squeeze through a small opening. I ended up enlargening this cutout with a cordless drill, and I made sure to adjust the CAD file to match this adjustment if I was ever to reprint that specific part in the future. 

<p align="center">
  <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/compare.png" width="500" />
</p>

Once the physical components were assembled, I moved on to wiring. I was fortunate to find online guides detailing how to wire the PCA9685 to the Arduino, as well as instructions for connecting the HC05 Bluetooth module, which required a simple voltage divider that I assembled on a compact breadboard. However, during my first test, I encountered a major problem. Due to the limited space in the robot arm’s base, a short circuit occurred between the On/Off switch and the PCA9685 board. This short damaged the main ground wire and destroyed the female DC power adapter that connected the arm to my power supply. After a lot of troubleshooting and rewiring, I managed to resolve these issues, and the robot arm finally operated as intended. Below is a video of the robot arm in action (click the image to access the link).

<p align="center">
  <a href="https://drive.google.com/file/d/1IjUJEja0Yv61JHg0KjAD3Q2Ghb71W-9r/view?usp=sharing">
    <img src="https://github.com/JakubPonulak/BlackMesaRobotArm/blob/main/Images/vid_img.png" width="300">
  </a>
</p>

## Conclusion
This project gave me the opportunity to apply my engineering knowledge in a practical setting while exposing me to real-world challenges that engineers face daily. It allowed me to develop my mechanical, electrical, and software skills in a hands-on and rewarding way. I highly recommend this type of project to anyone passionate about Mechanical Engineering who wants to gain valuable, multidisciplinary experience.

This project is licensed under the MIT License, which allows anyone to use, modify, and share the content, provided they give proper credit to the original author.
