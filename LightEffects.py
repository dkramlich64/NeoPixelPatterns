import board
from neopixel import NeoPixel
import time
import random

np = NeoPixel(board.D2, 30, auto_write=False, brightness=0.3)

RED = 0
GREEN = 1
BLUE = 2

MAX = 255

color = [255, 0, 0]
decrease = 0
increase = 1
count = 0

def rainbow_static():
    np.fill(color)
    np.show()
    time.sleep(0.03)
    if count == 255:
        decrease = (decrease + 1) % 3
        increase = (increase + 1) % 3
    else:
        color[decrease] -= 1
        color[increase] += 1
    count = (count + 1) % 256


def fade_in(color):
    red_step = color[RED] / MAX
    green_step = color[GREEN] / MAX
    blue_step = color[BLUE] / MAX
    for i in range(MAX + 1):
        new_color =  [int(i * red_step), int(i * green_step), int(i * blue_step)]
        np.fill(new_color)
        np.show()
        time.sleep(0.01)

def fade_out(color):
    red_step = color[RED] / MAX
    green_step = color[GREEN] / MAX
    blue_step = color[BLUE] / MAX
    for i in range(MAX + 1):
        new_color =  [color[RED] - int(i * red_step), color[GREEN] - int(i * green_step), color[BLUE] -int(i * blue_step)]
        np.fill(new_color)
        np.show()
        time.sleep(0.01)

def color_transition(start, end):
    red_mod, green_mod, blue_mod = 1, 1, 1
    if start[RED] < end[RED]:
        red_mod = -1
    if start[GREEN] < end[GREEN]:
        green_mod = -1
    if start[BLUE] < end[BLUE]:
        blue_mod = -1
        
    red_step = abs(start[RED] - end[RED]) / MAX
    green_step = abs(start[GREEN] - end[GREEN]) / MAX
    blue_step = abs(start[BLUE] - end[BLUE]) / MAX

    for i in range(MAX + 1):
        new_color =  [start[RED] - int(red_mod * i * red_step), start[GREEN] - int(green_mod * i * green_step), start[BLUE] -int(blue_mod * i * blue_step)]
        print(new_color)
        np.fill(new_color)
        np.show()
        time.sleep(0.05)
   

def sparkle(background, foreground):
    for i in range(60):
        np.fill(background)
        for j in range(5):
            np[random.randint(0, 29)] = foreground
        np.show()
        time.sleep(0.05)

while True:
    color_transition([1, 255, 1], [255, 1, 255])
    color_transition([255, 1, 255], [1, 255, 1])
    '''        
    fade_in([255, 0, 128])
    fade_out([255, 0, 128])
    fade_in([0, 0, 255])
    fade_out([0, 0, 255])
    fade_in([64, 255, 0])
    fade_out([64, 255, 0])
    sparkle([0, 0, 255], [255, 64, 0])
    sparkle([127, 0, 0], [0, 127, 255])
    '''
