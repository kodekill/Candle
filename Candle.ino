#include <Adafruit_NeoPixel.h>
#define PIN 2
#define NUMPIXELS 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int time = 0; 

void setup() {
  strip.begin();
  Serial.begin(9600);
}

void loop() {
  time = random(200,500); 
  Serial.println(time);
  LED(time);
}



int LED(int time) {
  strip.setPixelColor(0, strip.Color(64,32,0));
  strip.setPixelColor(2, strip.Color(64,32,0));
  strip.show();
  delay(time); 

}

