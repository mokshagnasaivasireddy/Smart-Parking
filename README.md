# Smart Parking System using Automatic License Plate Recognition (ALPR)

## Overview

The Smart Parking System is an IoT-based parking automation project that streamlines vehicle entry, parking time tracking, fee calculation, and exit verification. The system combines Automatic License Plate Recognition (ALPR), Arduino-based gate control, RFID payment simulation, and cloud-based data logging to minimize manual intervention and improve parking efficiency.

A hybrid architecture is used where the Arduino Uno manages hardware components while a laptop performs image processing, database management, and billing operations.

---

## Features

- Automatic vehicle detection using IR sensors
- License plate recognition using OpenCV and EasyOCR
- Automated entry and exit gate control
- Cloud-based vehicle data logging
- Parking duration tracking
- Automated fee calculation
- RFID-based payment simulation
- Serial communication between Arduino and PC
- Real-time user interface for monitoring system status

---

## Technologies Used

### Programming Language
- Python
- Arduino (C/C++)

### Libraries
- OpenCV
- EasyOCR
- PySerial

### Hardware
- Arduino Uno R3
- RFID RC522 Module
- 2 × IR Sensors
- 2 × Servo Motors
- Laptop Webcam
- Breadboard
- Jumper Wires

### Database
- Google Sheets / Cloud Database

---

## System Architecture

The project follows a three-layer architecture:

### Perception Layer
- IR Sensors
- Laptop Webcam
- RFID RC522
- Servo Motors

### Communication Layer
- Arduino Uno R3
- USB Serial Communication

### Application Layer
- License Plate Recognition (ALPR)
- Cloud Database
- Billing Engine
- User Interface

---

## Working Principle

### Entry Process

1. The entry IR sensor detects an approaching vehicle.
2. Arduino sends an `ENTRY_DETECTED` signal to the PC.
3. The laptop webcam captures the vehicle's license plate.
4. OpenCV and EasyOCR recognize the plate number.
5. Vehicle details and entry timestamp are stored in the cloud database.
6. The PC sends an `OPEN_GATE_ENTRY` command.
7. Arduino rotates the servo motor to open the entry gate.
8. After the vehicle passes, the gate closes automatically.

---

### Exit Process

1. The exit IR sensor detects the vehicle.
2. Arduino sends an `EXIT_DETECTED` signal.
3. The webcam captures the license plate.
4. The system retrieves the stored entry record.
5. Parking duration is calculated.
6. Parking charges are generated.
7. The user taps an RFID card for payment verification.
8. After successful verification, the PC sends an `OPEN_GATE_EXIT` command.
9. Arduino opens the exit gate.
10. The vehicle record is updated as exited in the cloud database.

---

## Billing Logic

- First **120 seconds** → ₹10
- Every additional **1 minute** → +₹10

---

## Project Workflow

```
Vehicle
     │
     ▼
IR Sensor Detection
     │
     ▼
Arduino Uno
     │
USB Serial Communication
     │
     ▼
Laptop Webcam
     │
     ▼
OpenCV + EasyOCR
     │
     ▼
Cloud Database
     │
     ▼
Billing Engine
     │
     ▼
RFID Verification
     │
     ▼
Servo Motor
     │
     ▼
Gate Opens
```

---

## Project Outcomes

- Automated vehicle entry and exit
- Accurate license plate recognition
- Reliable parking duration tracking
- Automated fee calculation
- Stable serial communication between Arduino and PC
- Cloud-based parking record management
- Reduced manual intervention

---

## Future Enhancements

- Raspberry Pi standalone implementation
- UPI payment gateway integration
- Mobile application
- Real-time parking analytics dashboard
- Improved ALPR accuracy using AI models
- Secure cloud authentication and encryption

---

## Learning Outcomes

- Embedded Systems
- Internet of Things (IoT)
- Computer Vision
- Automatic License Plate Recognition (ALPR)
- OpenCV
- EasyOCR
- Arduino Programming
- Serial Communication
- Cloud Database Integration
- RFID Interfacing

## License

This project was developed as an academic project for the Department of Electronics and Communication Engineering, SRM University AP.

## Team Members

Mokshagna Sai V
Sachithanand B
