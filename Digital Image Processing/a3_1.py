import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread('Lena.png', cv2.IMREAD_GRAYSCALE)
intensity_ranges = [255, 128, 64, 32, 16, 8, 4, 2]

downsampled_images = []
for i in intensity_ranges:
    image_norm = cv2.normalize(image, None, 0, i-1, cv2.NORM_MINMAX)
    downsampled_image = cv2.resize(
        image_norm, (128, 128), interpolation=cv2.INTER_AREA)
    downsampled_images.append(downsampled_image)

plt.figure(figsize=(12, 12))
plt.subplot(3, 3, 1)
plt.imshow(image, cmap='gray')
plt.axis('off')
plt.title('Original Image')
for i in range(8):
    plt.subplot(3, 3, i + 2)
    plt.imshow(downsampled_images[i], cmap='gray')
    plt.axis('off')
    plt.title('Intensity range: 0 - ' + str(intensity_ranges[i]))
plt.show()
