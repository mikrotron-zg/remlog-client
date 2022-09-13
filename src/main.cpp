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

// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Credentials.h" // see CredentialsTemplate.h for instructions first!

// Global variables
WiFiClient client;
HTTPClient http;
const String server_path = "http://" + String(REMLOG_IP_ADDRESS) + ":" +
                            String(REMLOG_PORT) + "/logs/device/" +
                            String(DEVICE_ID);
int counter = 1;

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

void log(String content) {
  // Send log to remlog server
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Not connected to WiFi, trying to reconnect");
    if (!connectToWiFi()) {
      Serial.println("Reconnect failed, not sending log!");
      return;
    }
  }
  Serial.print("Sending log content: ");
  Serial.println(content);

  String json = "{\"content\":\"" + content + "\"}";
  Serial.print("Formatted JSON: ");
  Serial.println(json);

  http.begin(client, server_path);
  http.addHeader("Content-Type", "application/json");
  int httpResponse = http.POST(json);
  delay (500);
  Serial.println("Server response:" + String(httpResponse));

  http.end();
}

void setup() {
  // Program start
  Serial.begin(115200);
  delay(5000);
  connectToWiFi();
  Serial.println("Sending start log to:");
  Serial.println(server_path);
  log("Device started at: " + String(millis()));
}

void loop() {
  // Program loop
  delay(60000); // wait a minute! ;-)
  log("Periodic log entry #" + String(counter));
  counter++;
}