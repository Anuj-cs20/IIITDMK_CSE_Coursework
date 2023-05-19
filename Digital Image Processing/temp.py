import cv2
import numpy as np

# Load image
image = cv2.imread("Lena.png")

# Convert to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Calculate gradients using Sobel
gx = cv2.Sobel(gray, cv2.CV_32F, 1, 0)
gy = cv2.Sobel(gray, cv2.CV_32F, 0, 1)

# Calculate magnitude and orientation
mag, ang = cv2.cartToPolar(gx, gy)

# Define parameters for HOG
winSize = (64, 128)
blockSize = (16, 16)
blockStride = (8, 8)
cellSize = (8, 8)
nbins = 9

# Create HOG descriptor
hog = cv2.HOGDescriptor(winSize, blockSize, blockStride, cellSize, nbins)

# Compute HOG features
features = hog.compute(gray)

# Display image and HOG features
# cv2.imshow("Image", image)
cv2.imshow("HOG features", features)
cv2.waitKey(0)
cv2.destroyAllWindows()
