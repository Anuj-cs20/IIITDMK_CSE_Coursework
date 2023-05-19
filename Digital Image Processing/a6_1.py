import numpy as np
import cv2


def gaussian_kernel(size, sigma):
    x, y = np.mgrid[-size//2 + 1:size//2 + 1, -size//2 + 1:size//2 + 1]
    g = np.exp(-((x**2 + y**2)/(2.0*sigma**2)))
    return g/g.sum()


def correlation(image, kernel):
    k_h, k_w = kernel.shape
    # for convolution flip the kernel by 180 degrees
    # kernel = np.flipud(np.fliplr(kernel))
    i_h, i_w = image.shape
    output = np.zeros_like(image)
    for i in range(k_h//2, i_h-k_h//2):
        for j in range(k_w//2, i_w-k_w//2):
            # Extract the region of interest (ROI) from the image
            roi = image[i-k_h//2:i+k_h//2+1, j-k_w//2:j+k_w//2+1]

            # Compute the correlation between the ROI and the kernel
            output[i, j] = np.sum(roi * kernel)

    return output


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
