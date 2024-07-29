### Ultrasonic Distance Measurement System based on ATmega32

#### **Objective:**
To design and implement a distance measurement system utilizing an ATmega32 microcontroller and an HC-SR04 ultrasonic sensor. The system will measure distance and display the results on a 4x16 LCD.

#### **System Overview:**
The system uses the ATmega32 microcontroller operating at 8 MHz to interface with the HC-SR04 ultrasonic sensor. The HC-SR04 sensor emits ultrasonic pulses and measures the time it takes for the echoes to return, which is used to calculate the distance. The measured distance is then displayed on a 4x16 LCD.

#### **Hardware Components:**
- **ATmega32 Microcontroller**: Serves as the central controller.
- **HC-SR04 Ultrasonic Sensor**: Measures distance using ultrasonic waves.
- **4x16 LCD**: Displays the measured distance.
- **GPIO and ICU Drivers**: For interfacing with the sensor and LCD.

#### **Software Architecture:**
The software is designed following a layered architecture model to ensure modularity and ease of maintenance. The key components include:

1. **GPIO Driver:**
   - Manages general-purpose input/output pins for interfacing with the sensor and LCD.
   - Controls the trigger pin for the ultrasonic sensor and data pins for the LCD.

2. **ICU (Input Capture Unit) Driver:**
   - Configured to detect rising edges from the ultrasonic sensor.
   - Handles timing calculations to measure the pulse duration.
   - Functions include `ICU_init` and `ICU_setCallBack` for initialization and callback setup.

3. **LCD Driver:**
   - Uses an 8-bit data mode to communicate with the 4x16 LCD.
   - Controls the LCD's display functions and data updates.

4. **Ultrasonic Driver:**
   - **`Ultrasonic_init(void)`**: Initializes ICU and sets up the trigger pin.
   - **`Ultrasonic_Trigger(void)`**: Sends a pulse to the ultrasonic sensor.
   - **`uint16 Ultrasonic_readDistance(void)`**: Measures distance by triggering the sensor and calculating the pulse duration.
   - **`Ultrasonic_edgeProcessing(void)`**: Callback function to process pulse duration and compute distance.

#### **Implementation:**
1. **Initialization:**
   - The `Ultrasonic_init` function sets up the ICU for rising edge detection and configures the GPIO for the trigger pin.
   - The LCD is initialized to display the distance readings.

2. **Distance Measurement:**
   - The `Ultrasonic_Trigger` function sends a trigger pulse to the HC-SR04 sensor.
   - The `Ultrasonic_readDistance` function initiates the measurement process, calculates the time for the echo to return, and converts it into a distance value.
   - The `Ultrasonic_edgeProcessing` function processes the pulse duration to determine the distance and updates the LCD.

3. **Display:**
   - The measured distance is continuously updated on the 4x16 LCD, providing real-time feedback.

#### **Conclusion:**
The ultrasonic distance measurement system effectively utilizes the ATmega32 microcontroller and HC-SR04 sensor to measure and display distance. The use of layered architecture and modular drivers ensures the system is efficient, maintainable, and capable of accurate distance measurement. The LCD provides a clear and continuous display of the measured distance, making the system practical for various applications.
