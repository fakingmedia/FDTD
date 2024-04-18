import numpy as np

import matplotlib.pyplot as plt

size = 200

for i in range(45):
    with open("sim." + str(10*i), "r") as f:
        plt.clf()
        data = f.read()
        l = list(float(i) for i in data.split())
        x = np.arange(size)
        y = np.array(l)
        plt.ylim((-0.5, 1.5))
        plt.plot(x, y)
        plt.savefig("sim." + str(10*i) + ".png")
    plt.ioff()