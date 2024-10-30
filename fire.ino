void fire(uint8_t bRed, uint8_t bGreen, uint8_t bBlue, uint8_t fRed, uint8_t fGreen, uint8_t fBlue) {
  float intensity;
  uint8_t bgRed, bgGreen, bgBlue, fgRed, fgGreen, fgBlue;
  for(int i = 0; i < 20; i++) {
      intensity = (float)random(30, 100) / 100;
      bgRed = (int)(intensity * bRed);
      bgGreen = (int)(intensity * bGreen);
      bgBlue = (int)(intensity * bBlue);
      strip.fill(strip.Color(bgRed, bgGreen, bgBlue));
      int num_flame = random(2, (int)(strip.numPixels()/5));
      for(int j = 0; j < num_flame; j++) {
        intensity = (float)random(30, 100) / 100;
        fgRed = (int)(intensity * fRed);
        fgGreen = (int)(intensity * fGreen);
        fgBlue = (int)(intensity * fBlue);
        int pixIndex = random(0, strip.numPixels()-1);
        strip.setPixelColor(pixIndex, strip.Color(fgRed, fgGreen, fgBlue));
      }
      strip.show();
      delay(60);
  }
