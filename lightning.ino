void lightning(uint8_t bRed, uint8_t bGreen, uint8_t bBlue, uint8_t fRed, uint8_t fGreen, uint8_t fBlue) {
  strip.fill(strip.Color(bRed, bGreen, bBlue));
  strip.show();
  int numFlashes = random(2, 6);
  for(int i = 0; i < numFlashes; i++) {
    strip.fill(strip.Color(fRed, fGreen, fBlue));
    strip.show();
    int wait = random(5, 60);
    delay(wait);
    strip.fill(strip.Color(bRed, bGreen, bBlue));
    strip.show();
    delay(wait);
  }
}
