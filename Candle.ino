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
  //Serial.println(time);
  LED(time,0);
  
  time = random(200,500); 
  LED(time,2);
}

void LED_on(int pix){
   strip.setPixelColor(pix, strip.Color(64,32,0));
   strip.show();
}


int LED(int time, int pix) {
  
 int brightLow = random(50, 100);  // Creates a lower bound pixel intensity
 int brightHigh = random(120, 200);  // Creates a high bound pixel intensity
 int brightMed = brightHigh - brightLow; // Sets up a medium value for the flicker brightness
 
 int flicker = random (1, 12);
 int flick_times = random (1, 3);
 
 if (flicker == 1){
   for (int j = 0; j <= flick_times; j++){
     int flick_speed = random(50, 200);

     strip.setBrightness(brightMed);
     LED_on(pix);
     delay(flick_speed);

     strip.setBrightness(brightLow);
     LED_on(pix);
     delay(flick_speed);
   }
   strip.setBrightness(brightMed);
   LED_on(pix);
 }
 
 else 
 
  for (int i = brightLow; i <= brightHigh; i++)
    {
      strip.setBrightness(i);
      LED_on(pix);
      delay(time/3);
    }
  delay(time);

  for (int i = brightHigh; i >= brightLow; i--)
    {
      strip.setBrightness(i);
      LED_on(pix);
      delay(time/2);
    }
  delay(time);
}


//void LED_off(pix){
//  strip.setPixelColor(pix, strip.Color(0,0,0));
//}

