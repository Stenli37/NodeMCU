#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "Stenli";
const char* password = "s99711106";


void setup() {
  ArduinoOTA.onStart([]() {
  String url = "https://github.com/Stenli37/NodeMCU.git"; // Replace with the actual URL of your hosted binary file

});
  pinMode(23,INPUT_PULLUP);
  pinMode(5,OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);

  }

  ArduinoOTA.setHostname("MyESP32");

  // No authentication by default
  ArduinoOTA.setPassword("MyOTApassword");

  // Initialize OTA
  ArduinoOTA.begin();
}

void loop() {
  digitalWrite(5,HIGH);
  ArduinoOTA.handle();
  if (digitalRead(23) == LOW) { // Example: Check if GPIO 2 is pulled LOW
    ArduinoOTA.begin(); // This will trigger the OTA update process
  }
}