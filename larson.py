# imports
import board
import time
from neopixel import NeoPixel

np = NeoPixel(board.D2, 30, auto_write=False, brightness=0.1)

index = 0
direction = 1
while True:
    np.fill((0, 0, 0))
    np[index] = (192, 0, 0)
    if index + 1 < np.n:
        np[index + 1] = (31, 0, 0)
    if index + 2 < np.n:
        np[index + 2] = (15, 0, 0)
    if index - 1 >= 0:
        np[index - 1] = (31, 0, 0)
    if index - 2 >= 0:
        np[index - 2] = (15, 0, 0)
    np.show()
    time.sleep(0.07)
    index += direction
    if index >= np.n-1 or index <= 0:
        direction *= -1
        
