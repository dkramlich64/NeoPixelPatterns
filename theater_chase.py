import time
import board
from neopixel import NeoPixel

red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
orange = (255, 32, 0)
purple = (64, 0, 255)
black = (0, 0, 0)

np = NeoPixel(board.D8, 50, auto_write=False, brightness=1.0, pixel_order="RGB")

display_colors = [orange, orange, black, purple, black]

def theater_chase(colors, repeat, forward, speed):
    global np
    if forward:
        loop = np.n - 1
        direction = -1
    else:
        loop - 0
        direction = 1
    for i in range(repeat):
        for j in range(np.n):
            np[j] = colors[(j+loop)%len(colors)]
        np.show()
        time.sleep(speed)
        loop = (loop + direction) % np.n
    

while True:
    theater_chase(display_colors, 10, True, 0.1)
