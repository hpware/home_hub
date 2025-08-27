
Home
Projects
Inspect
Libraries
Boards
Platforms
Devices
RegistryInstalledBuilt-inUpdates
FastLED by Daniel Garcia
FastLED is a library for programming addressable rgb led strips (APA102/Dotstar, WS2812/Neopixel, LPD8806, and a dozen others) acting both as a driver and as a library for color management and fast math.
Installation
|More info

ExamplesInstallationHeadersChangelog
 EspI2SDemo
// Simple test for the I2S on the ESP32dev board.
// IMPORTANT:
//   This is using examples is built on esp-idf 4.x. This existed prior to Arduino Core 3.0.0.
//   To use this example, you MUST downgrade to Arduino Core < 3.0.0
//   or it won't work on Arduino.

#ifdef ESP32



#define FASTLED_ESP32_I2S
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 1

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);

  // This is a no-op but tests that we have access to gCntBuffer, part of the
  // i2s api. You can delete this in your own sketch. It's only here for testing
  // purposes.
  if (false) {
    int value = gCntBuffer;
    value++;
  }
}

#else  // ESP32

// Non-ESP32 platform - provide minimal example for compilation testing
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
}

#endif  // ESP32
Tags
Platforms
Frameworks
Authors
Daniel Garcia (maintainer)
https://github.com/focalintent
Mark Kriegsman (maintainer)
https://github.com/kriegsman
Sam Guyer (maintainer)
https://github.com/samguyer
Jason Coon (maintainer)
https://github.com/jasoncoon
Josh Huber (maintainer)
https://github.com/uberjay
Zach Vorhies (maintainer)
https://github.com/zackees
Resources
 Registry
 Homepage
 Repository
Downloads
77 in the last day
1942 in the last week
9067 in the last month
Versions
3.10.2 released 4 days ago
3.10.1 released 2 months ago
3.10.0 released 2 months ago
3.9.20 released 2 months ago
3.9.19 released 3 months ago
3.9.17 released 3 months ago
3.9.18 released 3 months ago
3.9.16 released 4 months ago
3.9.15 released 4 months ago
3.9.14 released 5 months ago
3.9.13 released 7 months ago
3.9.12 released 7 months ago
3.9.11 released 7 months ago
3.9.10 released 7 months ago
3.9.9 released 7 months ago
3.9.8 released 8 months ago
3.9.7 released 8 months ago
3.9.6 released 8 months ago
3.9.5 released 8 months ago
3.9.4 released 9 months ago
3.9.3 released 9 months ago
3.9.2 released 9 months ago
3.9.1 released 10 months ago
3.9.0 released 10 months ago
3.8.0 released 11 months ago
3.7.8 released 11 months ago
3.7.7 released 11 months ago
3.7.6 released 11 months ago
3.7.5 released 11 months ago
3.7.4 released a year ago
3.7.3 released a year ago
3.7.2 released a year ago
3.7.1 released a year ago
3.7.0 released a year ago
3.6.0 released 2 years ago
3.5.0 released 3 years ago
3.4.0 released 5 years ago
3.3.3 released 5 years ago
3.3.2 released 6 years ago
Web·Open Source·Get Started·Docs·News·Community·Contact Us
If you enjoy using PlatformIO, please star our projects on GitHub!
PlatformIO Core