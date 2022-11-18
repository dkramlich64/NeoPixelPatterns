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

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t orange = strip.Color(255, 127, 0);
uint32_t purple = strip.Color(127, 0, 255);
#define NUM_COLORS 6
uint32_t colors[NUM_COLORS] = {red, green, yellow, blue, orange, purple};
uint32_t color1 = strip.Color(127, 0, 0);
uint32_t color2 = strip.Color(127, 127, 127);
#define NUM_COLORS2 4
uint32_t colors2[NUM_COLORS2] = {color1, color1, color2, color2};

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  theater_wipe();
  candy_theater();
  reverse_clear_wipe();
  colored_wipe();
  colored_xmas();
  colored_xmas_sparkle();
  clear_wipe();  
}

void clear_strip() {
  for(int i = 0; i < NUM_PIX; i++)
    strip.setPixelColor(i, 0);
  strip.show();
}

void colored_xmas() {
  for(int i = 0; i < NUM_PIX; i++)
      strip.setPixelColor(i, strip.Color(0, 0, 0));
  for(int i = 0; i < NUM_PIX / 2; i++)
  {
    strip.setPixelColor(i * 2, colors[i%NUM_COLORS]);
  }
  strip.show();
  delay(10000);  
}

void colored_wipe() {
  for(int i = 0; i < NUM_PIX / 2; i++)
  {
    strip.setPixelColor(i * 2, colors[i%NUM_COLORS]);
    strip.show();
    delay(6);
  }
}

void theater_wipe() {
  for(int i = NUM_PIX-1; i >= 0; i--)
  {
    strip.setPixelColor(i, colors2[i%NUM_COLORS2]);
    strip.show();
    delay(3);
  }
}

void clear_wipe() {
  for(int i = 0; i < NUM_PIX; i++)
  {
    strip.setPixelColor(i, 0);
    strip.show();
    delay(3);
  }
}

void reverse_clear_wipe() {
  for(int i = NUM_PIX-1; i >= 0; i--)
  {
    strip.setPixelColor(i, 0);
    strip.show();
    delay(3);
  }
}
void colored_xmas_sparkle() {
  for(int count = 0; count < 100; count++)
  {
    for(int i = 0; i < NUM_PIX; i++)
        strip.setPixelColor(i, strip.Color(0, 0, 0));
    for(int i = 0; i < NUM_PIX / 2; i++)
    {
      strip.setPixelColor(i * 2, colors[i%NUM_COLORS]);
    }
    for(int i = 0; i < NUM_PIX / 10; i++)
    {
      strip.setPixelColor(random(0, NUM_PIX/2) * 2, strip.Color(127, 127, 127));
    }
    strip.show();
    delay(75);  
  }
}

void candy_theater() {

  int j = 0;
  
  for(int count = 0; count < 100; count++) {
    
    for(int i = 0; i < NUM_PIX; i++)
    {
      strip.setPixelColor(i, colors2[(i+j)%NUM_COLORS2]);    
    }
    strip.show();
    j++;
    j = j % 4;
    delay(75);  
  }
}
