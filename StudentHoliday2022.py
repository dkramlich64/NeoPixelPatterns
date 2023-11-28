import board
import neopixel
import time
import random

BRIGHTNESS = .25
num_pixels = 30
np = neopixel.NeoPixel(board.A7, num_pixels, brightness=BRIGHTNESS, auto_write=False)

def starry_night(color1, color2, loop):
        np.fill(color1)
        np[int(num_pixels/2)] = color2
        np[int(num_pixels/2 + 1)] = color2
        np[int(num_pixels/2 - 1)] = color2
        np.show()
        for i in range(random.randint(0, int(num_pixels/6))):
            intensity = random.random() * 0.3 + 0.2
            foreground = [int(i * intensity) for i in color2]
            np[random.randint(0, num_pixels-1)] = foreground
        np.show()
        time.sleep(0.088)

while True:
    starry_night([2, 0, 13], [88, 88, 75], 10)

import board
import time
import random
import neopixel

np = neopixel.NeoPixel(board.A3, 30, brightness=0.5, auto_write=False)


red = [255, 0, 0]
green = [0, 255, 0]
blue = [0, 0, 255]
purple = [255, 255, 0]
yellow = [0, 255, 255]
white = [255, 255, 255]
black = [0, 0, 0]
christmas_colors = (red, green, blue, purple, yellow)

def enter_santa(delay=0.5):
    i = 0
    for i in range(0, 3):
        np[i] = red
        if i == 1:
            np[i-1] = white
        if i >= 2:
            np[i-1] = white
            np[i-2] = red
    np.show()
    time.sleep(delay)

def santa(col_list, delay=0.5):
    i = 0
    for i in range(np.n):
        if i <= (np.n - 4):
            if i%2 == 0:
                np[i] = random.choice(col_list)
            else:
                np[i] = black
            np[i+1] = red
            np[i+2] = white
            np[i+3] = red
            np.show()
            time.sleep(delay)
            i+=4

enter_santa()
santa(christmas_colors)

import board
import digitalio as dio
import time
import neopixel
import random

num_pixels = 30
np = neopixel.NeoPixel(board.A7, num_pixels, brightness=1, auto_write=False)

"""
Name: middle
Description: This function take a color and pulses it from both ends of the LED strip to the 
middle and then blackens it from the same ends
Parameters: colors(tuple) - This is the RGB value that will be pulsed. stop(floating point) - this will control how fast each pulse is
Return: none
"""
def middle(colors, stop):
    color = colors
    for i in range(0, num_pixels/2, 1):
        np[i] = color[i%len(color)]
        np.show()
        time.sleep(stop)
        np[num_pixels - 1 - i] = color[i%len(color) - 1]
        np.show()
        time.sleep(stop)
    for i in range(num_pixels):
        np[i] = (0, 0, 0)
        np.show()
        time.sleep(stop)
        np[num_pixels - 1 - i] = (0, 0, 0)
        np.show()
        time.sleep(stop)

import board
import neopixel
import time
import random
import digitalio as dio

num_pixels = 30
rgb = neopixel.NeoPixel(board.A3, num_pixels, brightness=0.1, auto_write=False)

def fade_out(color, sec = 0.001):
    mx = max(color[0], max(color[1], color[2]))
    r_inc = color[0]/mx
    g_inc = color[1]/mx
    b_inc = color[2]/mx
    r, g, b = color
    while r > 0 and g > 0 and b >= 0:
        r -= r_inc
        g -= g_inc
        b -= b_inc
        print(r, g, b)
        rgb.fill((int(r), int(g), int(b)))
        rgb.show()
        time.sleep(sec)

def fade_in(color, sec = 0.001):
    r, g, b = color
    r1 = r
    g1 = g
    b1 = b
    mx = max(color[0], max(color[1], color[2]))
    r_inc = color[0]/mx
    g_inc = color[1]/mx
    b_inc = color[2]/mx
    r = 0
    b = 0
    g = 0
    while r < r1  and g < g1 and b < b1:
        r += r_inc
        g += g_inc
        b += b_inc
        rgb.fill((int(r), int(g), int(b)))
        rgb.show()
        time.sleep(sec)

def stripes(space, color, colorsize, num_pixels):
    index = space
    once = False
    if space>0 and space <30:
        stripe = int(num_pixels / colorsize)
    else:
        stripe = int(num_pixels)
    for i in range(stripe):
        if space <= colorsize:
            if index > num_pixels-(space) and once:
                time.sleep(1)
                break
        else:
            if index > num_pixels-(colorsize) and once:
                time.sleep(1)
                break
        for j in range(colorsize):
            rgb[j+index]= color
            rgb.show()
            time.sleep(.1)
        index += (colorsize + space)
        once = True
        
def get_rid(color, num_pixels, space, colorsize):
    origspace = space
    times = int(num_pixels / space)
    for j in range(times):
        if space <= colorsize:
            if space > num_pixels-(space):
                time.sleep(1)
                break
        else:
            if space > num_pixels-(colorsize):
                time.sleep(1)
                break
        for i in range(colorsize):
            rgb[i+space] = color
            rgb.show()
            time.sleep(.1)
        space+=origspace

while True:
    white = [40,200,255]
    fade_in(white)
    stripes(3,[255,0,0],3,30)
    get_rid(white, 30, 3, 3)
    fade_out(white)
