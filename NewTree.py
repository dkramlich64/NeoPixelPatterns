import time
import board
from neopixel import NeoPixel
import random

red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
orange = (255, 32, 0)
purple = (64, 0, 255)
black = (0, 0, 0)
white = (127, 127, 127)

np = NeoPixel(board.GP2, 100, auto_write=False, brightness=1.0, pixel_order="RGB")

display_colors = [red, orange, orange, black, red, black, green, black]
xmas_colors = [red, blue, orange, green, purple]

def theater_chase(colors, repeat, forward=True, speed=0.05):
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

def sparkle(color_list, sparkle_color):
    for loop in range(150):
        for i in range(np.n):
            np[i] = color_list[i % len(color_list)]
        for i in range(np.n // 6):
            np[random.randint(0, np.n-1)] = sparkle_color
        np.show()
        time.sleep(0.09)     

def random_fill(color_list):
    unfilled = [i for i in range(np.n)]
    for i in range(np.n):
        choice = random.choice(unfilled)
        unfilled.remove(choice)
        np[choice] = color_list[choice % len(color_list)]
        np.show()
        time.sleep(0.1)

def random_wipe(color):
    unfilled = [i for i in range(np.n)]
    for i in range(np.n):
        choice = random.choice(unfilled)
        unfilled.remove(choice)
        np[choice] = color
        np.show()
        time.sleep(0.1)

def grinch_wipe(color):
    unfilled = [i for i in range(np.n)]
    for i in range(np.n):
        choice = random.choice(unfilled)
        unfilled.remove(choice)
        np[choice] = green
        np.show()
        time.sleep(0.3)
        np[choice] = color
        np.show()
        time.sleep(0.03)        
        for i in range(2):
            np[choice] = green
            np.show()
            time.sleep(0.03)
            np[choice] = color
            np.show()
            time.sleep(0.03)

np.fill(black)
np.show()
while True:
    random_fill(xmas_colors)
    time.sleep(5)
    sparkle(xmas_colors, (127, 127, 127))
    random_fill(xmas_colors)
    grinch_wipe(black)
    time.sleep(2)
    random_fill(xmas_colors)
    theater_chase(xmas_colors, np.n*2, speed=0.23)
    random_wipe(black)
    

