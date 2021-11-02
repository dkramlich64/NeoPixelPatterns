import board
import neopixel
import random
import time

num_pixels = 30
np = neopixel.NeoPixel(board.D6, num_pixels, brightness=1, auto_write=False)

np.fill(0x000000)
np.show()
index = 2
index2 = 0
brightness = 0.005
direction = 0.005
while True:
    for i in range(num_pixels):
        if i < num_pixels / 2:
            if i % 3 == index2:
                np[i] = 0xFF0000
            elif i % 3 == (index2 + 1)%3:
                np[i] = 0x00FF00
            else:
                np[i] = 0x0000FF
        else:
            if i % 3 == index:
                np[i] = 0xFF00FF
            elif i % 3 == (index + 1)%3:
                np[i] = 0xFFFF00
            else:
                np[i] = 0x00FFFF
    np.brightness = brightness
    np.show()
    time.sleep(0.1)
    index+=1
    index2-=1
    if index > 2:
        index = 0
    if index2 < 0:
        index2 = 2
    if brightness <= 0 or brightness >= 1:
        direction *= -1
    brightness += direction
