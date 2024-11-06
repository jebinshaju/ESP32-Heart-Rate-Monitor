#define BLYNK_TEMPLATE_ID "Your_Blynk_Template_ID"
#define BLYNK_TEMPLATE_NAME "HeartRate"
#define BLYNK_AUTH_TOKEN "Your_Blynk_Auth_Token"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
const char* ssid = "Your_SSID";
const char* password = "Your_WIFI_Password";

// Blynk credentials
char auth[] = BLYNK_AUTH_TOKEN;

// Define the pulse sensor settings
const int pulsePin = 32; // the pulse sensor pin
const int ledPin = 33;   // the LED pin
int pulseValue;          // the pulse sensor value
int bpm;                 // the heart rate in beats per minute

const unsigned long timeout = 30000; // 30 seconds timeout

BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  delay(1000); // Allow time for the serial monitor to initialize

  // Initialize the LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  unsigned long startAttemptTime = millis();

  // Blink LED while connecting to WiFi
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < timeout) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(ledPin, HIGH); // Indicate successful connection
  } else {
    Serial.println("\nFailed to connect to WiFi within the timeout period.");
    digitalWrite(ledPin, LOW); // Indicate failure
  }

  // Now initialize Blynk
  if (WiFi.status() == WL_CONNECTED) {
    Blynk.config(auth);
    if (Blynk.connect()) {
      Serial.println("Connected to Blynk");
    } else {
      Serial.println("Failed to connect to Blynk");
    }
  }

  // Set up the pulse sensor
  pinMode(pulsePin, INPUT);

  // Set up a timer to measure heart rate periodically
  timer.setInterval(1000L, measureHeartRate); // Measure every second
}

void loop()
{
  Blynk.run();
  timer.run();
}

void measureHeartRate()
{
  // Read the pulse sensor value
  pulseValue = analogRead(pulsePin);

  // Detect the pulse
  if (pulseValue > 600) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(100);                 // Wait for a short time
    digitalWrite(ledPin, LOW);  // Turn off the LED

    // Calculate the heart rate in beats per minute
    // Note: This calculation is a placeholder and may not be accurate.
    bpm = 180000 / pulseValue;

    // Send the heart rate to Blynk
    Blynk.virtualWrite(V0, bpm);

    // Print the heart rate on the serial monitor
    Serial.print("Heart rate: ");
    Serial.print(bpm);
    Serial.println(" BPM");
  }
}
