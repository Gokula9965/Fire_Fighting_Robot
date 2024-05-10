#define BLYNK_TEMPLATE_ID "TMPL3Lcc0Hsvk"
#define BLYNK_TEMPLATE_NAME "Subashhhh"
#define BLYNK_AUTH_TOKEN "ybmr2d6kic1CcxsCjStRbCHyPogiOB6u"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Wi-Fi credentials
const char* ssid = "JioFiber-PtyNd";
const char* password = "Drax@3412";

// Blynk authentication token
char auth[] = BLYNK_AUTH_TOKEN;

// Pin configurations
const int ledPin = LED_BUILTIN; // Built-in LED pin

// Blynk virtual pin
const int flameVirtualPinX = V0; // Virtual pin for X-axis accelerometer value
const int flameVirtualPinY = V1; // Virtual pin for Y-axis accelerometer value
const int flameVirtualPinZ = V2; // Virtual pin for Z-axis accelerometer value

BlynkTimer timer;

void sendSensor() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); // Read the input line
    
    // Serial.print(data);
    int flame1, flame2, flame3;
    sscanf(data.c_str(), "Flame Sensor 1: %d | Flame Sensor 2: %d | Flame Sensor 3: %d", &flame1, &flame2, &flame3);

    Serial.print("Flame Sensor 1: ");
    Serial.print(flame1);
    Serial.print(" | Flame Sensor 2: ");
    Serial.print(flame2);
    Serial.print(" | Flame Sensor 3: ");
    Serial.println(flame3);

    // Send values to Blynk
    Blynk.virtualWrite(flameVirtualPinX, flame1);
    Blynk.virtualWrite(flameVirtualPinY, flame2);
    Blynk.virtualWrite(flameVirtualPinZ, flame3);

    // Example threshold check (you may adjust this according to your needs)
    if ((flame1 > 500 && flame1 < 600) || (flame2 > 500 && flame2 < 600) || (flame3 > 500 && flame3 < 600)) {
      digitalWrite(ledPin, HIGH); // Turn off LED
      Blynk.logEvent("flame_detected", "Flame Detected");
    } else {
      digitalWrite(ledPin, LOW); // Turn on LED
    }
  }
}

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Blynk.begin(auth, ssid, password); // Connect to Blynk
  timer.setInterval(1000L, sendSensor); // Setup Blynk timer
}

void loop() {
  Blynk.run(); // Run Blynk
  timer.run(); // Run Blynk timer
}
