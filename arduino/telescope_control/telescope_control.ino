#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h>

#include "secrets.h"   // WiFi & MQTT credentials
#include "Motor.h"     // Motor class
#include "mqtt.h"      // MQTT logic
#include "motion.h"    // Motor movement logic

// Global hardware and state instances
WiFiClient espClient;
PubSubClient client(espClient);

Motor raMotor(0, 2, 16, 50000.0);   // RA axis motor (D4, D5)
Motor decMotor(13, 12, 15, 40000.0); // DEC axis motor (D6, D7)

bool isBusy = false;
bool isStopped = false;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(1000);
    ESP.restart();
  }

  // Enable OTA
  ArduinoOTA.setHostname(OTA_HOST);
  ArduinoOTA.setPassword(OTA_PASS);
  ArduinoOTA.begin();

  // Setup MQTT
  client.setServer(MQTT_HOST, 1883);
  client.setCallback(mqttCallback);

  reconnectMQTT(); // Subscribe to topics

  // Disable motors
  raMotor.setEnable(false);
  decMotor.setEnable(false);
}

void loop() {
  ArduinoOTA.handle();

  if (!client.connected()) {
    reconnectMQTT();
  }

  client.loop();
}
