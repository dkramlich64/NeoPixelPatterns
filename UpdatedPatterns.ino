#include <Adafruit_NeoPixel.h>

#define LED_PIN 2

#define LED_COUNT 300

#define MAX 255

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

long red = strip.Color(127, 0, 0);
long green = strip.Color(0, 127, 0);
long blue = strip.Color(0, 0, 127);
long yellow = strip.Color(127, 127, 0);
long orange = strip.Color(127, 32, 0);
long cyan = strip.Color(0, 127, 127);
long magenta = strip.Color(127, 0, 127);
long white = strip.Color(127, 127, 127);
long darkBlue = strip.Color(0, 0, 32);
long darkGreen = strip.Color(0, 32, 0);

long colors[] = {red, green, blue, yellow, cyan, magenta};

void setup() {
  strip.begin();
  strip.show();

}

void loop() {
  theaterChase2Color(127, 32, 0, 0, 0, 0, 5, 50);
  // rainbow();
  sparkle(red, white);
  // sparkle(darkGreen, magenta);
  sparkle(darkBlue, orange);
  // for(int i = 0; i < (sizeof(colors)/sizeof(long)); i++)
  //   bounce(1, colors[i]);
  fullFade(127, 0, 0, 3);
  fullFade(127, 127, 127, 3);
  fullFade(0, 0, 127, 3);
  fullFade(127, 32, 0, 3);

}

void colorWheel(unsigned char value) {
  int red = 0, green = 0, blue = 0;

  if (value <= 85) {
    red = 255 - (value * 3);
    green = value * 3;
  }
  else if (value <= 170) {
    value -= 85;
    green = 255 - (value * 3);
    blue = value * 3;
  }
  else {
    value -= 170;
    blue = 255 - (value * 3);
    red = value * 3;
  }
  // int color[] = {red, green, blue};
  // return color;

}

void rainbow() {

}

void fullFade(int red, int green, int blue, int delayAmt) {
  fadeIn(red, green, blue, delayAmt);
  delay(1000);
  fadeOut(red, green, blue, delayAmt);
  delay(1000);
}


void fadeOut(int red, int green, int blue, int delayAmt) {
  float redStep, greenStep, blueStep;
  int newRed, newGreen, newBlue;

  redStep = (float) red / MAX;
  greenStep = (float) green / MAX;
  blueStep = (float) blue / MAX;
  for(int i = 0; i <= MAX; i++) {
    newRed = red - (int) (i * redStep);
    newGreen = green - (int) (i * greenStep);
    newBlue = blue - (int) (i * blueStep);
    strip.fill(strip.Color(newRed, newGreen, newBlue));
    strip.show();
    delay(delayAmt);
  }
}

void fadeIn(int red, int green, int blue, int delayAmt) {
  float redStep, greenStep, blueStep;
  int newRed, newGreen, newBlue;

  redStep = (float) red / MAX;
  greenStep = (float) green / MAX;
  blueStep = (float) blue / MAX;
  for(int i = 0; i <= MAX; i++) {
    newRed = (int) (i * redStep);
    newGreen = (int) (i * greenStep);
    newBlue = (int) (i * blueStep);
    strip.fill(strip.Color(newRed, newGreen, newBlue));
    strip.show();
    delay(delayAmt);
  }
}

void sparkle(long background, long sparkleColor) {
  for(int j = 0; j < 100; j++) {
    if(background == 0)
      for(int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, colors[i%(sizeof(colors)/sizeof(long))]);
      }
    else
      strip.fill(background);
    
    long pixel;
    for(int i = 0; i < LED_COUNT / 20; i++) {
      pixel = random(0, LED_COUNT);
      strip.setPixelColor(pixel, sparkleColor);
    }
    strip.show();
    delay(50);
  }
}

void bounce(int reps, long color) {
  for(int j = 0; j < reps; j++) {
    for(int i = 0; i < LED_COUNT; i++) {
      strip.clear();
      strip.setPixelColor(i, color);
      strip.show();
      delay(25);
    }
    for(int i = 0; i < LED_COUNT; i++) {
      strip.clear();
      strip.setPixelColor(LED_COUNT-i-1, color);
      strip.show();
      delay(25);
    }
  }
}

void theaterChase2Color(int red1, int green1, int blue1, int red2, int green2, int blue2, int size, int delayAmt) {
  int count = 0;
  for(int i = 0; i < LED_COUNT; i++) {
    for(int j = 0; j < LED_COUNT; j++) {
      if ((j + count) % size >= 0 && (j + count) % size < (int)(size/2)) {
        strip.setPixelColor(j, strip.Color(red1, green1, blue1));
      }
      else {
        strip.setPixelColor(j, strip.Color(red2, green2, blue2));
      }
      
    }
    strip.show();
    delay(delayAmt);
    count++;
  }
}
