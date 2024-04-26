#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL6JCULZWSJ"
#define BLYNK_TEMPLATE_NAME "slingshot"
#define BLYNK_AUTH_TOKEN "eMzwNXRUkYt59yi6qsxoxqAqVn4-YPtV"

char ssid[] = "ARVR";
char pass[] = "STIC_LMES@007";

// Use the D5 pin for the IR sensor on the ESP8266 D1 Mini
int IR_sensor = D5;
int value = 0;

void setup() {
  pinMode(IR_sensor, INPUT);
  Serial.begin(9600);
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
