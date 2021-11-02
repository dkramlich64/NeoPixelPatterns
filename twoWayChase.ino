#include <Adafruit_NeoPixel.h>

#define NP_PIN 2

#define NUM_PIXELS 300

#define NUM_COLORS 5

int idx, idx2;

Adafruit_NeoPixel strip(NUM_PIXELS, NP_PIN, NEO_GRB + NEO_KHZ800);
  
void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(255);
  idx = NUM_COLORS - 1;
  idx2 = 0;
}

void loop() {
     twoWayChase();
} // loop


void twoWayChase()
{
  for(int j=0; j < 100; j++)
  {
    for(int i = 0; i < NUM_PIXELS; i++)
    {
      if (i < NUM_PIXELS / 2) {
        if (i % NUM_COLORS ==idx2)
          strip.setPixelColor(i, 255, 0, 0);
        else if (i % NUM_COLORS == ((idx2 + 1) % NUM_COLORS))
          strip.setPixelColor(i, 255, 31, 0);
        else if (i % NUM_COLORS == ((idx2 + 2) % NUM_COLORS))
          strip.setPixelColor(i, 255, 127, 0);
        else if (i % NUM_COLORS == ((idx2 + 3) % NUM_COLORS))
          strip.setPixelColor(i, 0, 255, 0);
        else
          strip.setPixelColor(i, 0, 0, 0);
      }
      else {
        if (i % NUM_COLORS ==idx)
          strip.setPixelColor(i, 255,0, 0);
        else if (i % NUM_COLORS == ((idx + 1) % NUM_COLORS))
          strip.setPixelColor(i, 255, 31, 0);
        else if (i % NUM_COLORS == ((idx + 2) % NUM_COLORS))
          strip.setPixelColor(i, 255, 127, 0);
        else if (i % NUM_COLORS == ((idx + 3) % NUM_COLORS))
          strip.setPixelColor(i, 0, 255, 0);
        else
          strip.setPixelColor(i, 0, 0, 0);
      } // else
    } // for i
    strip.show();
    idx--;
    idx2++;
    if (idx2 > NUM_COLORS-1)
      idx2 = 0;
    if (idx < 0)
      idx = NUM_COLORS - 1;
    delay(100);  
  } // for j
}
