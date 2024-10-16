# imports
import board
import time
from neopixel import NeoPixel
import random

# Setup / configuration
np = NeoPixel(board.D22, 30, auto_write=False, brightness=0.3)
np2 = NeoPixel(board.D23, 30, auto_write=False, brightness=0.3)
i = 0
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
yellow = (255, 255, 0)
cyan = (0, 255, 255)
magenta = (255, 0, 255)
purple = (64, 0, 16)
orange = (255, 32, 0)
black = (0, 0, 0)
white = (255, 255, 255)

color_list = [orange, black, red, black, purple, black, black]
loop, direction = 0, 1
curr_time = time.monotonic()
update_time1, update_time2 = 0, 0
delay1, delay2 = 0.08, 0.01
count = 1
forward = True

# def theater_chase(colors, repeat, forward, delay):
#     if forward:
#         loop = len(colors) - 1
#         direction = -1
#     else:
#         loop = 0
#         direction = 1
#     for i in range(repeat):
#         for pixel in range(np.n):
#             np[pixel] = colors[(pixel + loop) % len(colors)]
#         np.show()
#         time.sleep(delay)
#         loop = (loop + direction) % len(colors)

def theater_chase(colors):
    global loop, direction
    for pixel in range(np.n):
        np[pixel] = colors[(pixel + loop) % len(colors)]
    np.show()
    loop = (loop + direction) % len(colors)

def fade():
    global colors, red_orig, green_orig, blue_orig, count
    global max_step, red_ratio, green_ratio, blue_ratio, forward
    red, green, blue = 0, 0, 0
    if forward:
        red = red_orig - count * red_ratio
        green = green_orig - count * green_ratio
        blue = blue_orig - count * blue_ratio
        count += 1
        if count > 255:
            count = 1
            forward = not forward
    else:
        red = count * red_ratio
        green = count * green_ratio
        blue = count * blue_ratio
        count += 1
        if count > 255:
            count = 1
            forward = not forward
    np2.fill((red, green, blue))
    np2.show()
    print(forward, np2[0])

# main / infinite loop
colors = magenta
red_orig = colors[0]
green_orig = colors[1]
blue_orig = colors[2]
max_step = max(colors)
red_ratio = red_orig / max_step
green_ratio = green_orig / max_step
blue_ratio = blue_orig / max_step
while True:
    curr_time = time.monotonic()
    if curr_time > update_time1 + delay1:
        theater_chase(color_list)
        update_time1 = curr_time
    if curr_time > update_time2 + delay2:
        fade()
        update_time2 = curr_time


