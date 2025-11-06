#include <Adafruit_NeoPixel.h>

#define PIN 2

#define NUMPIXELS 30

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

long red = strip.Color(127, 0, 0);
long green = strip.Color(0, 127, 0);
long blue = strip.Color(0, 0, 127);
long yellow = strip.Color(127, 63, 0);
long orange = strip.Color(127, 31, 0);
long cyan = strip.Color(0, 127, 127);
long magenta = strip.Color(127, 0, 127);
long white = strip.Color(127, 127, 127);
long darkBlue = strip.Color(0, 0, 31);
long darkGreen = strip.Color(0, 31, 0);
long black = 0;

long colors[] = {red, red, orange, orange, yellow, yellow};

int sweep = 0;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < NUMPIXELS; i++)
  {
    strip.setPixelColor((i + sweep) % NUMPIXELS, (colors[i%6]));
  }
  long pixel;
  for(int i = 0; i < NUMPIXELS / 4; i++) 
  {
    pixel = random(0, NUMPIXELS);
    strip.setPixelColor(pixel, black);
  }
  strip.show();
  delay(100);
  sweep++;
  sweep = sweep % 6;
}
