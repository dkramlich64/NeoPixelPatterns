from neopixel import NeoPixel
import board
import time
import random

SEGMENT = 50
SECONDS = 2

red = (127, 0, 0)
green = (0, 127, 0)
blue = (0, 0, 127)
orange = (127, 64, 0)
cyan = (0, 127, 127)
magenta = (127, 0, 127)
white = (64, 64, 64)
purple = (92, 0, 127)
yellow = (127, 127, 0)
black = (0, 0, 0)

colors = [red, green, blue, orange, cyan, magenta, white, purple, yellow]

np = NeoPixel(board.NEOPIXEL, 10, auto_write=False, brightness=0.3)

def half_fade(is_even, new_color):
    if is_even:
        r, g, b = np[0]
    else:
        r, g, b = np[1]
    r_seg = r / SEGMENT
    g_seg = g / SEGMENT
    b_seg = b / SEGMENT
    
    if is_even:
        start = 0
    else:
        start = 1
    for seg in range(SEGMENT):
        for pixel in range(start, np.n, 2):
            np[pixel] = (r - int(r_seg * (seg + 1)), g - int(g_seg * (seg + 1)), b - int(b_seg * (seg + 1)))
        np.show()
        time.sleep(SECONDS/SEGMENT)
    r, g, b = new_color
    r_seg = r / SEGMENT
    g_seg = g / SEGMENT
    b_seg = b / SEGMENT
    for seg in range(SEGMENT):
        for pixel in range(start, np.n, 2):
            np[pixel] = (int(r_seg * (seg + 1)), int(g_seg * (seg + 1)), int(b_seg * (seg + 1)))
        np.show()
        time.sleep(SECONDS/SEGMENT)

for i in range(np.n):
    if i % 2 == 0:
        np[i] = (127, 0, 0)
    else:
        np[i] = (0, 127, 0)
np.show()
time.sleep(5)

while True:
    half_fade(True, (0, 127, 0))
    time.sleep(5)
    half_fade(False, (127, 0, 0))
    time.sleep(5)
    half_fade(True, (127, 0, 0))
    time.sleep(5)
    half_fade(False, (0, 127, 0))
    time.sleep(5)


