#pragma once

#include <PubSubClient.h>
#include "secrets.h"

extern WiFiClient espClient;
extern PubSubClient client;

// MQTT connect
void reconnectMQTT(const char* clientId, const char* subscribeTopic) {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT as ");
    Serial.print(clientId);
    Serial.println("...");

    if (client.connect(clientId)) {
      Serial.println("MQTT connected");
      client.subscribe(subscribeTopic);
      Serial.print("Subscribed to topic: ");
      Serial.println(subscribeTopic);
    } else {
      Serial.print("MQTT connection failed, rc=");
      Serial.println(client.state());
      delay(5000);
    }
  }
}