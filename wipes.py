def wipe(wipe_color, speed):
    '''
    Performs a wipe transistion
    '''
    for i in range(np.n):
        np[i] = wipe_color
        np.show()
        time.sleep(speed)

def reverse_wipe(wipe_color, speed):
    '''
    Performs a wipe in the opposite direction
    '''
    for i in range(np.n-1, -1, -1):
        np[i] = wipe_color
        np.show()
        time.sleep(speed)

def pattern_wipe(colors, speed):
    for i in range(np.n):
        np[i] = colors[i%len(colors)]
        np.show()
        time.sleep(speed)
def reverse_pattern_wipe(colors, speed):
    for i in range(np.n-1, -1, -1):
        np[i] = colors[i%len(colors)]
        np.show()
        time.sleep(speed)
