#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPL6JCULZWSJ"
#define BLYNK_TEMPLATE_NAME "slingshot"
#define BLYNK_AUTH_TOKEN "eMzwNXRUkYt59yi6qsxoxqAqVn4-YPtV"

const char* ssid = "ARVR";
const char* pass = "STIC_LMES@007";

// Use GPIO 14 (D5) pin for the IR sensor on the ESP32
int IR_sensor = 14;
int value = 0;

void setup() {
  pinMode(IR_sensor, INPUT);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // Read the value from the IR sensor
  value = digitalRead(IR_sensor);
  
  // Send the sensor value to the Blynk app
  Blynk.virtualWrite(V2, value);

  // Print the sensor value to serial monitor for debugging
  Serial.println(value);
  
  // Call Blynk.run() to handle communication with the Blynk server
  Blynk.run();

  // Add a small delay to avoid flooding the Blynk server
  delay(100);
}
