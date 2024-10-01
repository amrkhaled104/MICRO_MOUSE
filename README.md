# Micromouse Project

## #TOM THE RAT SLAYER TEAM

Welcome to the Micromouse project repository! This project showcases a small autonomous robot designed for maze navigation. Explore this project if you're interested in robotics and autonomous systems.

## Table of Contents
- [Hardware Components 🛠️](#hardware-components-🛠️)
- [Software 🧾](#software-🧾)
- [Algorithms 🧠](#algorithms-🧠)
- [Challenges We Faced ⚙️](#challenges-we-faced-⚙️)

## Hardware Components 🛠️
The Micromouse project utilizes the following hardware components:

### PCB (Printed Circuit Board) 🧩
![PCB FRONT](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/PCB/pcbb.jpg)
![PCB BACK](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/PCB/pcb4.jpg)

The central control hub that connects and manages all other components.

You can find all details and schematic [Here](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/Schematic.pdf).

### Infrared IR Obstacle Avoidance Sensor 3 Pin 🦇
![IR Sensor](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/ir/ir.jpg)

Detects lines and walls for precise navigation in mazes.

### Optical Encoder 🔍
![Optical Encoder](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/optical%20encoder/encoder_image.jpg)

Tracks wheel movements for accurate control.

### Wheels 🚗
![Wheels and Chassis](https://www.google.com/imgres?q=wheel%20n20%20motor&imgurl=https%3A%2F%2Fae01.alicdn.com%2Fkf%2FSd0ec6d5d20b34b0d99449805601db4e1u%2FD-hole-Rubber-Wheel-Suitable-for-N20-Motor-D-Shaft-Tire-Car-Robot-DIY-Toys.jpg&imgrefurl=https%3A%2F%2Fwww.aliexpress.com%2Fitem%2F32809043739.html)

The wheels of the robot.

### 3D Design 🖨️
![3D Design](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Mecanical/design.jpg)

For More Photos click [Here](https://github.com/amrkhaled104/MICRO_MOUSE/tree/main/Mecanical).

### Motors 🔄
![MiniQ Motor Wheel Set](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/Motor%26Wheel/N20%20motor.jpg)

Drive the wheels for movement.

### Freewheel (Caster Wheel) 🎡
![N20 Caster Robot Ball Wheel](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/caster/caster.jpg)

Provides stability and maneuverability during turns.

### Gyroscope (MPU6050) 🧭
![Gyroscope](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/Hardware/gyroscope/MPU.jpg)

Measures angles and helps maintain orientation for accurate navigation.

## Challenges We Faced ⚙️

The Micromouse project wasn't without its fair share of difficulties, and we encountered numerous challenges along the way. Here's a glimpse into what we went through:

## Simulation Video 🎥
Check out this video demonstrating the performance of our algorithm in action on the simulation software! This video showcases how the robot navigates the maze and makes real-time decisions. 

[![Watch the Simulation](https://github.com/amrkhaled104/MICRO_MOUSE/blob/main/algorithm/Untitled%20video%20-%20Made%20with%20Clipchamp.mp4)

### PCB Design and Hardware Availability

At the beginning of the project, we designed everything based on the assumption that we would handle all components on the PCB, expecting it to be the ultimate hardware solution. We calculated everything meticulously, but unfortunately, hardware availability in Egypt turned out to be less than ideal. The quality of some components was subpar, which forced us to adapt and compromise in certain areas.

### IR Sensor Issues

One of the biggest setbacks was with the IR sensors. Initially, we planned to build and calibrate our own IR sensors, but due to time constraints and repeated failures in making them work correctly, we were left with no choice but to purchase pre-built IR sensors. This decision was a significant pivot, but it saved us time and allowed us to stay on track with the project deadline.

### Faulty Controller from Makers

Another major problem we faced was with the microcontroller we ordered from Makers. After spending valuable time integrating it into our system, we realized that the controller was defective. We reached out to the company, and to their credit, they responded quickly and offered to send us a replacement. However, the replacement unit arrived only two hours before our final submission! We had to work under extreme pressure to integrate the new controller and test it in time for the final presentation. Luckily, we managed to get everything up and running just in time.
