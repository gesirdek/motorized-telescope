#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h>

#include "secrets.h"   // WiFi & MQTT credentials
#include "Motor.h" // Motor class
#include "mqtt.h"      // MQTT logic

// Global hardware and state instances
WiFiClient espClient;
PubSubClient client(espClient);

Motor fMotor(14, 12, 13, 15);

bool isBusy = false;
bool isStopped = false;

void setup() {
  Serial.begin(115200);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW); // Fan is off
  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(1000);
    ESP.restart();
  }

  // Enable OTA
  ArduinoOTA.setHostname(OTA_FOCUSER_HOST);
  ArduinoOTA.setPassword(OTA_FOCUSER_PASS);
  ArduinoOTA.begin();

  // Setup MQTT
  client.setServer(MQTT_HOST, 1883);
  client.setCallback(mqttCallback);

  reconnectMQTT("FocuserClient", "focuser/komut"); // Subscribe to topics
}

void loop() {
  ArduinoOTA.handle();

  if (!client.connected()) {
    reconnectMQTT("FocuserClient", "focuser/komut");
  }

  client.loop();
}
