
# ESP32 Heart Rate Monitor with Blynk Integration

This project uses an ESP32 microcontroller to monitor heart rate using a pulse sensor and sends the data to the Blynk IoT platform. The ESP32 connects to Wi-Fi, reads the pulse sensor input, calculates beats per minute (BPM), and transmits the heart rate data to the Blynk mobile app.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Hardware Requirements](#hardware-requirements)
3. [Software Requirements](#software-requirements)
4. [Circuit Diagram and Pin Connections](#circuit-diagram-and-pin-connections)
5. [Installation and Setup](#installation-and-setup)
6. [Usage](#usage)
7. [Troubleshooting](#troubleshooting)
8. [Contributing](#contributing)
9. [License](#license)

---

### Project Overview

This project uses the ESP32 microcontroller to read heart rate from a pulse sensor and displays it on the Blynk mobile app. This setup allows for remote monitoring of heart rate in real-time.

### Hardware Requirements

- **ESP32 Development Board**
- **Pulse Sensor** (compatible with ESP32, typically has 3 pins: VCC, GND, Signal)
- **Micro USB Cable** (for programming and power)
- **Computer** (with USB port and Arduino IDE installed)

### Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- **ESP32 Board Support** for Arduino IDE
- **Blynk Library** for Arduino

### Circuit Diagram and Pin Connections

| Pulse Sensor Pin | ESP32 Pin |
|------------------|-----------|
| VCC              | 3.3V      |
| GND              | GND       |
| Signal           | GPIO 32   |

- **LED Pin for Pulse Indication**: GPIO 33 on the ESP32

The LED will blink each time a pulse is detected, giving visual feedback of heartbeats.

### Installation and Setup

#### Step 1: Install Arduino IDE and ESP32 Board Support

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. In **Arduino IDE**, go to **File > Preferences**.
3. In **Additional Board Manager URLs**, add:

   ```
   https://dl.espressif.com/dl/package_esp32_index.json
   ```

4. Go to **Tools > Board > Board Manager**, search for "ESP32," and install the **ESP32 by Espressif Systems** package.

#### Step 2: Install Blynk Library

1. In **Arduino IDE**, go to **Sketch > Include Library > Manage Libraries**.
2. Search for **Blynk** and install **Blynk by Volodymyr Shymanskyy**.

#### Step 3: Clone or Download This Project

Clone this repository or download it as a ZIP file:

   ```bash
   git clone https://github.com/jebinshaju/ESP32-HeartRate-Monitor.git
   ```

Or download the ZIP file and extract it.

#### Step 4: Open the Project in Arduino IDE

1. Open `heart.ino` in Arduino IDE.
2. Select your ESP32 board:
   - Go to **Tools > Board** and choose **ESP32 Dev Module**.
3. Select the correct port:
   - Go to **Tools > Port** and select the port where your ESP32 is connected.

#### Step 5: Configure Wi-Fi and Blynk Credentials

1. Replace placeholders in the code with your Wi-Fi and Blynk credentials:

   ```cpp
   #define BLYNK_TEMPLATE_ID "Your_Blynk_Template_ID"
   #define BLYNK_TEMPLATE_NAME "HeartRate"
   #define BLYNK_AUTH_TOKEN "Your_Blynk_Auth_Token"
   ```

2. Enter your Wi-Fi SSID and password:

   ```cpp
   const char* ssid = "Your_SSID";
   const char* password = "Your_WIFI_Password";
   ```

3. Save your changes.

#### Step 6: Upload the Code to ESP32

1. Connect your ESP32 to your computer using a USB cable.
2. Click **Upload** in Arduino IDE to compile and upload the code to your ESP32.
3. Open the **Serial Monitor** (Ctrl + Shift + M) to view the output. Set the baud rate to `9600`.

### Usage

1. Open the Blynk app on your mobile device.
2. Create a new project and link it to your ESP32 with the Blynk authentication token.
3. Add a **Value Display** widget in the app and link it to **Virtual Pin V0** to display the heart rate (BPM).
4. When the ESP32 is connected, it will:
   - Display the heart rate in the Serial Monitor.
   - Send heart rate data to Blynk, which will be visible in the app.

### Troubleshooting

- **Issue: ESP32 does not connect to Wi-Fi**
  - Double-check the SSID and password.
  - Make sure your Wi-Fi network is available and within range.

- **Issue: No heart rate displayed on Blynk**
  - Verify that the pulse sensor is correctly connected.
  - Ensure that the Virtual Pin on Blynk is set to **V0**.

### Contributing

Contributions are welcome! Please fork this repository, make your changes, and submit a pull request.

---

### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

