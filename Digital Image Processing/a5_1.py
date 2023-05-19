import cv2
import matplotlib.pyplot as plt
import cv2
import numpy as np


def histogram_matching(img, ref):
    # Calculate histogram of the input and reference images
    hist_img, bins_img = np.histogram(img.flatten(), 256, [0, 256])
    hist_ref, bins_ref = np.histogram(ref.flatten(), 256, [0, 256])

    # Calculate cumulative distribution function (CDF) for input and reference images
    cdf_img = hist_img.cumsum()
    cdf_img = (cdf_img / float(cdf_img.max())) * 255
    cdf_ref = hist_ref.cumsum()
    cdf_ref = (cdf_ref / float(cdf_ref.max())) * 255

    # Create a lookup table
    lut = np.zeros(256, dtype=np.uint8)
    j = 0
    for i in range(len(cdf_img)):
        while j < len(cdf_ref) and cdf_ref[j] < cdf_img[i]:
            j += 1
        lut[i] = j

    # Apply the lookup table to the input image
    matched_img = cv2.LUT(img, lut)

    return matched_img


img = cv2.imread('./pout-dark.jpg', cv2.IMREAD_GRAYSCALE)

histogram = [0] * 256
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        intensity = img[i][j]
        histogram[intensity] += 1

cdf = [0] * 256
cdf[0] = histogram[0]
for i in range(1, 256):
    cdf[i] = cdf[i-1] + histogram[i]

map = [0] * 256
pixels = img.shape[0] * img.shape[1]
for i in range(256):
    map[i] = int(round((cdf[i] * 255.0) / pixels))

equalized = img.copy()
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        equalized[i][j] = map[img[i][j]]

cv2.imshow('Original', img)
cv2.imshow('Equalized', equalized)
cv2.waitKey(0)

ref = cv2.imread('pout-bright.jpg', 0)
img_specification = histogram_matching(img, ref)

cv2.imshow('Reference', ref)
cv2.imshow('Specification', img_specification)
cv2.waitKey(0)
cv2.destroyAllWindows()
