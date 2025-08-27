
Home
Projects
Inspect
Libraries
Boards
Platforms
Devices
RegistryInstalledBuilt-inUpdates
NTPClient by Fabrice Weinberg
An NTPClient to connect to a time server. Get time from a NTP server and keep it in sync.
Installation
|More info

ExamplesInstallationHeadersChangelog
 Basic
#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>

const char *ssid     = "<SSID>";
const char *password = "<PASSWORD>";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());

  delay(1000);
}
Tags
Platforms
Frameworks
Authors
Fabrice Weinberg (maintainer)
fabrice@weinberg.me
Resources
 Registry
 Repository
Downloads
71 in the last day
1428 in the last week
8362 in the last month
Versions
3.2.1 released 3 years ago
3.1.0 released 9 years ago
Web·Open Source·Get Started·Docs·News·Community·Contact Us
If you enjoy using PlatformIO, please star our projects on GitHub!
PlatformIO Core