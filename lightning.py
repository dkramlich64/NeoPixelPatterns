def lightning(background, foreground):
    print("Strike")
    np.fill(background)
    np.show()
    num_flashes = random.randint(2, 6)
    for i in range(num_flashes):
        np.fill(foreground)
        np.show()
        delay = random.randint(5, 60) / 1000
        time.sleep(delay)
        np.fill(background)
        np.show()
        time.sleep(delay)
