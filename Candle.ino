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
  LED1(time);

  time = random(200,500); 
  Serial.println(time);
  LED2(time);
}



int LED1(int time) {
  
 int brightLow = random(3, 64);
 int brightHigh = random(80, 256);
  
  for (int i = brightLow; i <= brightHigh; i++)
    {
      strip.setBrightness(i);
      strip.setPixelColor(0, strip.Color(64,32,0));
      strip.show();
      delay(time/3);
    }
  delay(time);

  for (int i = brightHigh; i >= brightLow; i--)
    {
      strip.setBrightness(i);
      strip.setPixelColor(0, strip.Color(64,32,0));
      strip.show();
      delay(time%3);
    }
  delay(time);
}

int LED2(int time) {
  
 int brightLow = random(3, 64);
 int brightHigh = random(80, 256);
  
  for (int i = brightLow; i <= brightHigh; i++)
    {
      strip.setBrightness(i);
      strip.setPixelColor(2, strip.Color(64,32,0));
      strip.show();
      delay(time/4);
    }
  delay(time);

  for (int i = brightHigh; i >= brightLow; i--)
    {
      strip.setBrightness(i);
      strip.setPixelColor(2, strip.Color(64,32,0));
      strip.show();
      delay(time%3);
    }
  delay(time);
}
 //strip.clear();
