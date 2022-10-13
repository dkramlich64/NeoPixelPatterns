import time
import board
import neopixel

np = neopixel.NeoPixel(board.A1, 30, brightness=0.3, auto_write=False)

def two_color_chase(color1, color2, size, delay=0.1):
    count = 0
    for i in range(np.n * 10):
        for j in range(np.n):
            if (j + count) % size >=0 and (j + count) % size < int(size/2):
                np[j] = color1
            else:
                np[j] = color2
        np.show()
        time.sleep(delay)
        count += 1

while True:
    two_color_chase((255, 63, 0), (63, 0, 255), 10, 0.04)
