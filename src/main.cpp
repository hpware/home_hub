#include <Arduino.h>
#include <FastLED.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const boolean debug = true;

#define NUM_LEDS 6
#define DHTPIN 2
#define DHTTYPE DHT11

const char* ssid = ""; //  I'm NOT leaking my home WiFi and password
const char* wifi_password = "";
const char* mqtt_server = "test.mosquitto.org";
const char* client_name = "esp8266-home-hub";
const int mqtt_port = 1883;

void callback(char* topic, byte* payload, unsigned int length) {
  for (uint8_t i = 0; i < length; i++) {
    Serial.write(payload[i]);
  }
  Serial.println();
}

DHT_Unified dht(DHTPIN, DHTTYPE);
WiFiClient Wifi;
PubSubClient client(mqtt_server, mqtt_port, callback, Wifi);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup() {
  dht.begin();
  WiFi.begin(ssid, wifi_password);
  if (client.connect(client_name)) {
    client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }
}

void loop() {
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  client.loop();
}
