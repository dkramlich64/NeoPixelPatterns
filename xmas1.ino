#include <Adafruit_NeoPixel.h>
//Hacked from the original Adafruit library demo

#define PIN 2   //my control pin
#define NUM_PIX 300

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIX, PIN, NEO_GRB + NEO_KHZ800);

uint32_t colors[5];

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colors[0] = strip.Color(127, 0, 0);
  colors[1] = strip.Color(0, 127, 0);
  colors[2] = strip.Color(79, 0, 127);
  colors[3] = strip.Color(127, 127, 0);
  colors[4] = strip.Color(0, 0, 127);
}

void loop() {
  candy_theater();
  red_green_sparkle();
  xmas_explosion();
  colored_xmas();
  colored_xmas_sparkle();
  red_green_theater();
}

void colored_xmas() {
  for(int i = 0; i < NUM_PIX/2; i++)
  {
    strip.setPixelColor(i*2, colors[i%5]);
    strip.setPixelColor(i*2+1, colors[i%5]);
  }

  strip.show();
  delay(10000);  
}


void colored_xmas_sparkle() {
  for(int count = 0; count < 100; count++)
  {
    for(int i = 0; i < NUM_PIX/2; i++)
    {
      strip.setPixelColor(i*2, colors[i%5]);
      strip.setPixelColor(i*2+1, colors[i%5]);
    }
    for(int i = 0; i < NUM_PIX / 10; i++)
    {
      strip.setPixelColor(random(0, NUM_PIX), strip.Color(127, 127, 127));
    }
    strip.show();
    delay(75);  
  }
}

void candy_theater() {
  uint32_t color1 = strip.Color(127, 0, 0);
  uint32_t color2 = strip.Color(127, 127, 127);
  int j = 0;

  for(int count = 0; count < 100; count++) {

    for(int i = 0; i < NUM_PIX; i+=4)
    {
      if (j % 4 == 0) {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color2);       
      }
      else if (j % 4 == 1) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color2);       
      }
      else if (j % 4 == 2) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color1);             
      }
      else {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color1);             
      }
    }
    strip.show();
    j++;
    if (j >= 4)
        j = 0;
    delay(75);  
  }
}

void red_green_theater() {
  uint32_t color1 = strip.Color(127, 0, 0);
  uint32_t color2 = strip.Color(0, 127, 0);
  int j = 0;

  for(int count = 0; count < 100; count++) {

    for(int i = 0; i < NUM_PIX; i+=4)
    {
      if (j % 4 == 0) {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color2);       
      }
      else if (j % 4 == 1) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color2);       
      }
      else if (j % 4 == 2) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color1);             
      }
      else {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color1);             
      }
    }
    strip.show();
    j++;
    if (j >= 4)
        j = 0;
    delay(75);  
  }
}

void red_green_sparkle()
{
  uint32_t color1 = strip.Color(127, 0, 0);
  uint32_t color2 = strip.Color(0, 127, 0);
  for(int count=0; count < 100; count++)
  {  
    for(int i = 0; i < NUM_PIX; i+=3)
    {
      if (i % 2 == 0)
      {
          strip.setPixelColor(i, color1);
          strip.setPixelColor(i+1, color1);
          strip.setPixelColor(i+2, color1);
      }
      else
      {
          strip.setPixelColor(i, color2);
          strip.setPixelColor(i+1, color2);
          strip.setPixelColor(i+2, color2);      
      }
    }
    for(int i = 0; i < NUM_PIX / 10; i++)
      {
        strip.setPixelColor(random(0, NUM_PIX), strip.Color(127, 127, 127));
      }
      strip.show();
      delay(75);
  }
}

void xmas_explosion() {
  for(int i = 0; i < NUM_PIX / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(127, 0, 0));
    strip.setPixelColor(NUM_PIX-i-1, strip.Color(0, 127, 0));
    strip.show();
    delay(20);
  }
  
  for(int i = NUM_PIX/2-1; i >= 0; i--)
  {
    int j = NUM_PIX/2-i + NUM_PIX/2-1;

    strip.setPixelColor(i, colors[(i%10)/2]);
    strip.setPixelColor(j, colors[(j%10)/2]);
    strip.show();
    delay(20);
  }
}
