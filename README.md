# Atmega32 All-In-One Drivers Library

This repository contains a complete and modular implementation of Hardware Abstraction Layer (HAL) and Microcontroller Abstraction Layer (MCAL) drivers for the Atmega32 microcontroller. Additionally, it includes a library layer that provides essential utilities like standard types, bit manipulation macros, and error types. These drivers and utilities are designed to facilitate efficient and scalable development for embedded systems based on the Atmega32.

## Overview

### Hardware Abstraction Layer (HAL)
The HAL drivers provide a high-level interface to the Atmega32's hardware peripherals. These drivers abstract the hardware-specific details, enabling developers to interact with the peripherals without needing to manage low-level operations.

#### HAL Components
- **Character LCD**
  - Initialization and configuration
  - Display text and custom characters
  - Cursor control
- **Seven Segment Display**
  - Initialization and configuration
  - Single and multi-digit displays
  - Segment control
- **Switch**
  - Debouncing and state detection
  - Support for multiple switches
- **Keypad**
  - Initialization and configuration
  - Key press detection
  - Matrix keypad support
- **Motors**
  - DC Motor control (direction and speed)
  - Stepper Motor control
  - Servo Motor control
- **Electrical Switches**
  - Relay control
  - Solenoid control

### Microcontroller Abstraction Layer (MCAL)
The MCAL drivers offer direct access to the Atmega32's microcontroller-specific features. These drivers are essential for managing the core functionalities such as timers, interrupts, and communication protocols.

#### MCAL Components
- **DIO (Digital Input/Output)**
  - Initialization and configuration of digital pins
  - Read and write operations
  - Pin change interrupt handling
- **PORT**
  - Port configuration and control
  - Pin direction and value settings
- **Interrupts**
  - Configuration of external and internal interrupts
  - Interrupt Service Routines (ISR) handling
  - Prioritization and management
- **ADC (Analog to Digital Converter)**
  - Initialization and configuration
  - Single and continuous conversion modes
  - Interrupt-based and polling-based data acquisition
- **Timer**
  - Initialization and configuration of timers
  - Support for different timer modes (Normal, CTC, PWM)
  - Interrupt handling
- **PWM (Pulse Width Modulation)**
  - Configuration of PWM channels
  - Duty cycle adjustment
  - Frequency control
- **UART (Universal Asynchronous Receiver/Transmitter)**
  - Initialization and configuration
  - Data transmission and reception
  - Interrupt-based communication
- **SPI (Serial Peripheral Interface)**
  - Master and slave configuration
  - Data transfer management
  - Interrupt-based and polling-based communication
- **I2C (Inter-Integrated Circuit)**
  - Master and slave configuration
  - Data transfer management
  - Multi-master support
- **EEPROM (Electrically Erasable Programmable Read-Only Memory)**
  - Read and write operations
  - Block and byte access
- **CAN (Controller Area Network)**
  - Initialization and configuration
  - Data transmission and reception
  - Error handling
- **LIN (Local Interconnect Network)**
  - Initialization and configuration
  - Data transmission and reception
  - Master and slave node support
- **RTOS (Real-Time Operating System)**
  - Task creation and management
  - Scheduling and synchronization
  - Inter-task communication

### Library Layer
The library layer provides essential utilities that are widely used across HAL and MCAL layers, ensuring code reusability and maintainability.

#### Library Components
- **STD_TYPES**
  - Standard data types (e.g., uint8_t, int16_t)
  - Type definitions for portability
- **BIT_MATH**
  - Bit manipulation macros (e.g., SET_BIT, CLEAR_BIT, TOGGLE_BIT)
  - Utilities for efficient bit-level operations
- **ERROR_TYPES**
  - Standard error codes and definitions
  - Error handling utilities


## Contributing
Contributions are welcome! Please fork the repository, create a new branch, and submit a pull request with your changes. Ensure that your code adheres to the project's coding standards and includes appropriate documentation.


By providing this repository, we aim to support the embedded systems community in developing robust and efficient applications using the Atmega32 microcontroller. Happy coding!
