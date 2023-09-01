import board
from neopixel import NeoPixel
import time

np = NeoPixel(board.NEOPIXEL, 1, auto_write=False, brightness=0.3)

color = [255, 0, 0]
decrease = 0
increase = 1

while True:
    for i in range(255):
        np.fill(color)
        np.show()
        time.sleep(0.01)
        color[decrease] -= 1
        color[increase] += 1
    decrease = (decrease + 1) % 3
    increase = (increase + 1) % 3

