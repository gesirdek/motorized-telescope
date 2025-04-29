#pragma once

#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "Motor.h"
#include "motion.h"
#include "secrets.h"

// External declarations
extern Motor raMotor;
extern Motor decMotor;

extern bool isBusy;
extern bool isStopped;

extern WiFiClient espClient;
extern PubSubClient client;

// MQTT message handler
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, payload, length);

  if (error) {
    client.publish("teleskop/status", "json parse error");
    return;
  }

  if (!doc.containsKey("command")) {
    client.publish("teleskop/status", "missing command");
    return;
  }

  String cmd = doc["command"].as<String>();

  if (cmd == "stop" && isBusy) {
    isStopped = true;
    client.publish("teleskop/status", "stopped");
    return;
  }

  if (cmd == "move") {
    if (isBusy) {
      client.publish("teleskop/status", "rejected: busy");
      return;
    }

    raMotor.setMovement(doc.containsKey("ra") ? doc["ra"]: 0);
    decMotor.setMovement(doc.containsKey("dec") ? doc["dec"]: 0);

    isBusy = true;
    isStopped = false;
    moveMotorMM();
    isBusy = false;

    if (!isStopped) client.publish("teleskop/status", "ready");
    return;
  }

  client.publish("teleskop/status", "unknown command");
}

// MQTT reconnect
void reconnectMQTT() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("TeleskopClient")) {
      Serial.println("MQTT connected");
      client.subscribe("teleskop/komut");
    } else {
      Serial.print("MQTT connection failed, rc=");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

