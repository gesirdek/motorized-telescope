#pragma once

#include <ArduinoJson.h>
#include "Motor.h"
#include "mqtt_base.h"

#define FAN_PIN D0  // GPIO16 (D0)

// External declarations
extern Motor fMotor;

extern bool isBusy;
extern bool isStopped;

// MQTT message handler
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, payload, length);

  if (error) {
    client.publish("focuser/status", "json parse error");
    return;
  }

  if (!doc.containsKey("command")) {
    client.publish("focuser/status", "missing command");
    return;
  }

  String cmd = doc["command"].as<String>();

  if (cmd == "stop" && isBusy) {
    isStopped = true;
    client.publish("focuser/status", "stopped");
    return;
  }

  if (cmd == "move") {
    if (isBusy) {
      client.publish("focuser/status", "rejected: busy");
      return;
    }

    float movement = doc.containsKey("mv") && doc["mv"].is<float>() ? doc["mv"].as<float>() : 0.0;

    isBusy = true;
    isStopped = false;
    digitalWrite(FAN_PIN, HIGH); // Fan start
    
    if (movement > 0) {
      fMotor.stepForward(movement);
    } else {
      fMotor.stepBackward(-movement);
    }


    digitalWrite(FAN_PIN, LOW);  // Fan stop
    isBusy = false;

    if (!isStopped) client.publish("focuser/status", "ready");
    return;
  }

  client.publish("focuser/status", "unknown command");
}


