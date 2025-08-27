
Home
Projects
Inspect
Libraries
Boards
Platforms
Devices
RegistryInstalledBuilt-inUpdates
PubSubClient by Nick O'Leary
A client library for MQTT messaging. MQTT is a lightweight messaging protocol ideal for small devices. This library allows you to send and receive MQTT messages. It supports the latest MQTT 3.1.1 protocol and can be configured to use the older MQTT 3.1 if needed. It supports all Arduino Ethernet Client compatible hardware, including the Intel Galileo/Edison, ESP8266 and TI CC3000.
Installation
|More info

ExamplesInstallationHeadersChangelog
 mqtt_stream
/*
 Example of using a Stream object to store the message payload

 Uses SRAM library: https://github.com/ennui2342/arduino-sram
 but could use any Stream based class such as SD

  - connects to an MQTT server
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic"
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <SRAM.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(172, 16, 0, 100);
IPAddress server(172, 16, 0, 2);

SRAM sram(4, SRAM_1024);

void callback(char* topic, byte* payload, unsigned int length) {
  sram.seek(1);

  // do something with the message
  for(uint8_t i=0; i<length; i++) {
    Serial.write(sram.read());
  }
  Serial.println();

  // Reset position for the next message to be stored
  sram.seek(1);
}

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient, sram);

void setup()
{
  Ethernet.begin(mac, ip);
  if (client.connect("arduinoClient")) {
    client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }

  sram.begin();
  sram.seek(1);

  Serial.begin(9600);
}

void loop()
{
  client.loop();
}
Tags
Platforms
Frameworks
Authors
Nick O'Leary
nick.oleary@gmail.com
https://github.com/knolleary
Resources
 Registry
 Repository
Downloads
109 in the last day
1839 in the last week
8955 in the last month
Versions
2.8 released 5 years ago
2.7 released 7 years ago
2.6 released 9 years ago
Web·Open Source·Get Started·Docs·News·Community·Contact Us
If you enjoy using PlatformIO, please star our projects on GitHub!
PlatformIO Core