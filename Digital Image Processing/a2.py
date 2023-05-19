import numpy as np
import matplotlib.pyplot as plt

f = plt.imread('Lena.png')

def Gaussian_noise(num):
    fi = []
    for i in range(num):
        noise = np.random.normal(0, 1, f.shape)
        fi.append(f + noise)

    g = sum(fi)/num

    plt.figure()
    plt.imshow(f, cmap='gray')
    plt.title('Original Image')

    plt.figure()
    plt.imshow(g, cmap='gray')
    plt.title('Average of Noisy Images')

    for i in range(num):
        plt.figure()
        plt.imshow(fi[i], cmap='gray')
        plt.title('Noisy Image ' + str(i+1))

    plt.show()


Gaussian_noise(5)
# Gaussian_noise(10)
# Gaussian_noise(20)
# Gaussian_noise(30)
