import numpy as np
import matplotlib.pyplot as plt

sizeX = 32
sizeY = 31
sizeZ = 31

for i in range(30):
    with open("sim." + str(10*i), "r") as f:
        plt.clf()

        data = f.read()
        l = list(float(i) for i in data.split())
        l1 = np.array(l)
        l2 = l1.reshape((sizeZ, sizeY))

        x = np.arange(sizeX)
        y = np.array(sizeY)


        plt.imshow(l2)
        plt.colorbar()
        plt.tight_layout()
        plt.savefig("sim." + str(10*i) + ".png")
    plt.ioff()