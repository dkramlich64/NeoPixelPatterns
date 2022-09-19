#include <Adafruit_NeoPixel.h>

#define LED_COUNT 300
#define LED_PIN    2

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}


void loop() {
  rainbow(10);
  theaterChase();
  // larson_scanner(255, 0, 0);
  double_larson_scanner(255, 0, 0, 10);
  larson_scanner_explode(255, 0, 0);
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

void theaterChase() {
  uint32_t color1 = strip.Color(244, 146, 0);
  uint32_t color2 = strip.Color(0, 0, 0);
  int j = 0;

  for(int count = 0; count < 200; count++) {

    for(int i = 0; i < LED_COUNT; i+=8)
    {
      if (j % 8 == 0) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color2);
        strip.setPixelColor(i+4, color1);
        strip.setPixelColor(i+5, color1);
        strip.setPixelColor(i+6, color1);
        strip.setPixelColor(i+7, color1);
      }
      else if (j % 8 == 1) {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color2);
        strip.setPixelColor(i+4, color2);
        strip.setPixelColor(i+5, color1);
        strip.setPixelColor(i+6, color1);
        strip.setPixelColor(i+7, color1);
        }
      else if (j % 8 == 2) {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color2);
        strip.setPixelColor(i+4, color2);
        strip.setPixelColor(i+5, color2);
        strip.setPixelColor(i+6, color1);
        strip.setPixelColor(i+7, color1);
        }
      else if (j % 8 == 3) {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color2);
        strip.setPixelColor(i+4, color2);
        strip.setPixelColor(i+5, color2);
        strip.setPixelColor(i+6, color2);
        strip.setPixelColor(i+7, color1);
        }
      else if (j % 8 == 4) {
        strip.setPixelColor(i, color1);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color1);
        strip.setPixelColor(i+4, color2);
        strip.setPixelColor(i+5, color2);
        strip.setPixelColor(i+6, color2);
        strip.setPixelColor(i+7, color2);
        }
      else if (j % 8 == 5) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color1);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color1);
        strip.setPixelColor(i+4, color1);
        strip.setPixelColor(i+5, color2);
        strip.setPixelColor(i+6, color2);
        strip.setPixelColor(i+7, color2);
        }
      else if (j % 8 == 6) {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color1);
        strip.setPixelColor(i+3, color1);
        strip.setPixelColor(i+4, color1);
        strip.setPixelColor(i+5, color1);
        strip.setPixelColor(i+6, color2);
        strip.setPixelColor(i+7, color2);
        }
      else {
        strip.setPixelColor(i, color2);
        strip.setPixelColor(i+1, color2);
        strip.setPixelColor(i+2, color2);
        strip.setPixelColor(i+3, color1);
        strip.setPixelColor(i+4, color1);
        strip.setPixelColor(i+5, color1);
        strip.setPixelColor(i+6, color1);
        strip.setPixelColor(i+7, color1);
        }
    }
    strip.show();
    j++;
    if (j >= 8)
        j = 0;
    delay(75);  
  }
}


 void larson_scanner(int red, int green, int blue) {
  uint32_t black = strip.Color(0, 0, 0);
  int index = 3, dir = 1;
  for(int j = 0; j < (LED_COUNT - 4) * 10; j++) {
    for(int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, black);
    }
    strip.setPixelColor(index, strip.Color(red, green, blue));
    strip.setPixelColor(index-1, strip.Color((int)(red*0.5), (int)(green*0.5), (int)(blue*0.5)));
    strip.setPixelColor(index+1, strip.Color((int)(red*0.5), (int)(green*0.5), (int)(blue*0.5)));
    strip.setPixelColor(index-2, strip.Color((int)(red*0.2), (int)(green*0.2), (int)(blue*0.2)));
    strip.setPixelColor(index+2, strip.Color((int)(red*0.2), (int)(green*0.2), (int)(blue*0.2)));
    strip.show();
    delay(10);
    if (index < 2) {
      dir *= -1;
    }
    if (index >= LED_COUNT-2) {
      dir *= -1;
    }
    index += dir;
  }
 }


 void double_larson_scanner(int red, int green, int blue, int count) {
  uint32_t black = strip.Color(0, 0, 0);
  int index1 = 3, dir1 = 1, index2 = LED_COUNT - 3, dir2 = -1;
  for(int j = 0; j < (LED_COUNT - 4) * count; j++) {
    for(int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, black);
    }
    strip.setPixelColor(index1, strip.Color(255-red, 255-green, 255-blue));
    strip.setPixelColor(index1-1, strip.Color((int)(red*0.5), (int)(green*0.5), (int)(blue*0.5)));
    strip.setPixelColor(index1+1, strip.Color((int)(red*0.5), (int)(green*0.5), (int)(blue*0.5)));
    strip.setPixelColor(index1-2, strip.Color((int)(red*0.2), (int)(green*0.2), (int)(blue*0.2)));
    strip.setPixelColor(index1+2, strip.Color((int)(red*0.2), (int)(green*0.2), (int)(blue*0.2)));

    strip.setPixelColor(index2, strip.Color(red, green, blue));
    strip.setPixelColor(index2-1, strip.Color((int)((255-red)*0.5), (int)((255-green)*0.5), (int)((255-blue)*0.5)));
    strip.setPixelColor(index2+1, strip.Color((int)((255-red)*0.5), (int)((255-green)*0.5), (int)((255-blue)*0.5)));
    strip.setPixelColor(index2-2, strip.Color((int)((255-red)*0.2), (int)((255-green)*0.2), (int)((255-blue)*0.2)));
    strip.setPixelColor(index2+2, strip.Color((int)((255-red)*0.2), (int)((255-green)*0.2), (int)((255-blue)*0.2)));    
    strip.show();
    delay(5);
    if (index1 < 2) {
      dir1 *= -1;
    }
    if (index2 < 2) {
      dir2 *= -1;
    }
    if (index1 >= LED_COUNT-2) {
      dir1 *= -1;
    }
     if (index2 >= LED_COUNT-2) {
      dir2 *= -1;
    }   
    index1 += dir1;
    index2 += dir2;
  }
 }

void larson_scanner_explode(int red, int green, int blue) {
  uint32_t black = strip.Color(0, 0, 0);
  int index1 = 3, dir1 = 1, index2 = LED_COUNT - 3, dir2 = -1;
  for(int j = 0; j < (LED_COUNT - 2) / 2; j++) {
    for(int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, black);
    }
    strip.setPixelColor(index1, strip.Color(255-red, 255-green, 255-blue));
    strip.setPixelColor(index1-1, strip.Color((int)(red*0.5), (int)(green*0.5), (int)(blue*0.5)));
    strip.setPixelColor(index1+1, strip.Color((int)(red*0.5), (int)(green*0.5), (int)(blue*0.5)));
    strip.setPixelColor(index1-2, strip.Color((int)(red*0.2), (int)(green*0.2), (int)(blue*0.2)));
    strip.setPixelColor(index1+2, strip.Color((int)(red*0.2), (int)(green*0.2), (int)(blue*0.2)));

    strip.setPixelColor(index2, strip.Color(red, green, blue));
    strip.setPixelColor(index2-1, strip.Color((int)((255-red)*0.5), (int)((255-green)*0.5), (int)((255-blue)*0.5)));
    strip.setPixelColor(index2+1, strip.Color((int)((255-red)*0.5), (int)((255-green)*0.5), (int)((255-blue)*0.5)));
    strip.setPixelColor(index2-2, strip.Color((int)((255-red)*0.2), (int)((255-green)*0.2), (int)((255-blue)*0.2)));
    strip.setPixelColor(index2+2, strip.Color((int)((255-red)*0.2), (int)((255-green)*0.2), (int)((255-blue)*0.2)));    
    strip.show();
    delay(5);
    if (index1 < 2) {
      dir1 *= -1;
    }
    if (index2 < 2) {
      dir2 *= -1;
    }
    if (index1 >= LED_COUNT-2) {
      dir1 *= -1;
    }
     if (index2 >= LED_COUNT-2) {
      dir2 *= -1;
    }   
    index1 += dir1;
    index2 += dir2;
  }
  rainbow_half_display();
}


void rainbow_half_display() {
  int rainbow[strip.numPixels()];
  for(int i=0; i<strip.numPixels(); i++) { 
    int pixelHue = (i * 65536L / strip.numPixels());
    rainbow[i] = strip.gamma32(strip.ColorHSV(pixelHue));
  }
  int half = strip.numPixels() / 2;
  for(int i=0; i < half; i++) {
    strip.setPixelColor(half+i, rainbow[half+i]);
    strip.setPixelColor(half-i, rainbow[half-i]);
    strip.show();
    delay(8);
  }    
}
