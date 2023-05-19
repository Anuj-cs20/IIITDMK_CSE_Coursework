import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('Lena.png', cv2.IMREAD_GRAYSCALE)
sizes = [128, 64, 32, 16]
resized_images = [cv2.resize(img, (size, size)) for size in sizes]

plt.subplot(2, 3, 1), plt.imshow(img, cmap='gray')
plt.title("Original Image")

for i, resized_img in enumerate(resized_images):
    plt.subplot(2, 3, i + 2), plt.imshow(resized_img, cmap='gray')
    plt.title(f"Size: {sizes[i]}x{sizes[i]}")

plt.show()
