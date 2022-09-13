 /*******************************************************************
  * Remlog-client 
  * 
  * Simple Arduino application to test 
  * remlog server (https://github.com/mikrotron-zg/remlog).
  * Based on ESP32 dev board.
  * 
  * 2022 by Mikrotron d.o.o.
  * see the project root for license info
  *******************************************************************/

#include <Arduino.h>
#include <WiFi.h>
#include "Credentials.h" // see CredentialsTemplate.h for instructions first!

bool connectToWiFi() {
  // Connect to WiFi network
  Serial.print("Connecting to WiFi network: ");Serial.println(WIFI_SSID);
  WiFi.mode(WIFI_STA);
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  }
  if (WiFi.waitForConnectResult() == WL_CONNECTED) {
    Serial.println("WiFi connected!");
    return true;
  } 
  Serial.println("WiFi not connected, check your credentials");
  return false;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting...");
  if (connectToWiFi()) {
    // TODO startup log
  }
}

void loop() {
  // TODO periodic log
}