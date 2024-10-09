void theater_chase(uint32_t *color_array, int number, uint8_t repeat, bool forward) {
  uint8_t loop, direction;
  if (forward) {
    loop = number - 1;
    direction = -1;
  }
  else {
    loop = 0;
    direction = 1;
  }
  for(int j = 0; j < repeat; j++) {
    for(int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, color_array[(i + loop) % number]);
    }
    strip.show();
    delay(100);
    loop = (loop + direction) % number;
  }
