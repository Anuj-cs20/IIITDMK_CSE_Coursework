import cv2
import numpy as np

# load image
img = cv2.imread("lena.png",0)

# add noise without normalizing
noise = np.random.normal(loc=0, scale=50, size=img.shape)
img_noise = img + noise

# normalize image
img = img/255.0

# add noise to normalized image
noise = np.random.normal(loc=0, scale=0.2, size=img.shape)
img_normalized_noise = img + noise

# display images
cv2.imshow("Original", img)
cv2.imshow("Noise without normalization", img_noise)
cv2.imshow("Normalized image with noise", img_normalized_noise)
cv2.waitKey(0)
cv2.destroyAllWindows()
