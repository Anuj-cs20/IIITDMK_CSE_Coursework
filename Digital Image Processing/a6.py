import numpy as np
import cv2


def gaussian_kernel(filter_size, sigma):
    kernel = np.zeros((filter_size, filter_size), np.float32)
    a = filter_size//2
    for x in range(-a, a + 1):
        for y in range(-a, a + 1):
            x1 = 2*np.pi*(sigma**2)
            x2 = np.exp(-(x**2 + y**2)/(2 * sigma**2))
            kernel[x + a][y + a] = (1/x1)*x2
    return kernel/kernel.sum()


def correlation(img, kernel):
    row, col = img.shape
    a, b = kernel.shape
    a = a//2
    b = b//2
    new_img = np.zeros((row, col), np.uint8)
    for i in range(row):
        for j in range(col):
            sum = 0.0
            for x in range(-a, a + 1):
                for y in range(-b, b+1):
                    if i + x < 0 or i + x >= row or j + y < 0 or j + y >= col:
                        sum = sum + kernel[x + a][y + b]*0
                    else:
                        sum = sum + kernel[x + a][y + b]*img[i + x][j + y]
            new_img[i][j] = sum
    return new_img


img = cv2.imread('Lena.png', cv2.IMREAD_GRAYSCALE)

noisy_imgs = list()
for noise_quantity in np.arange(0.1, 1.1, 0.1):
    noisy_img = img.copy()

    row, col = noisy_img.shape
    salt_pepper_pixels = np.random.choice(
        row*col, size=int(noise_quantity*row*col), replace=False)

    noisy_img.flat[salt_pepper_pixels] = np.random.choice(
        [0, 255], size=len(salt_pepper_pixels))

    noisy_imgs.append(noisy_img)

sigma = 1
lst = [3, 5, 7]
for x in lst:
    kernel = gaussian_kernel(x, sigma)
    for i in range(10):
        filtered_img = cv2.filter2D(noisy_imgs[i], -1, kernel)
        cv2.imshow('using filter2D Filtered Image', filtered_img)
        filtered_img = correlation(noisy_imgs[i], kernel)
        cv2.imshow('Filtered Image', filtered_img)
        cv2.imshow(f'Noisy Image - Noise Quantity: .{i + 1}', noisy_imgs[i])
        cv2.waitKey(0)
        cv2.destroyAllWindows()
