import cv2
import numpy as np
from scipy import ndimage

image = cv2.imread('watershed.jpeg')

# Convert to grayscale and apply Gaussian blur
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(gray, (11, 11), 0)

# Threshold the image
_, thresh = cv2.threshold(blur, 220, 255, cv2.THRESH_BINARY_INV)

# Perform the distance transform algorithm
dist_transform = cv2.distanceTransform(thresh, cv2.DIST_L2, 5)
_, sure_fg = cv2.threshold(dist_transform, 0.7 * dist_transform.max(), 255, 0)

# Find unknown region
sure_fg = np.uint8(sure_fg)
unknown = cv2.subtract(thresh, sure_fg)

# Marker labelling
_, markers = cv2.connectedComponents(sure_fg)

# Add one to all labels so that sure background is not 0, but 1
markers = markers + 1

# Now, mark the region of unknown with zero
markers[unknown == 255] = 0

# Apply the watershed algorithm
markers = cv2.watershed(image, markers)
image[markers == -1] = [255, 0, 0]

# Count the number of connected components, ignoring the background
n_components = np.max(markers) - 1

print(f"Number of connected components (circles): {n_components}")

# Display the output image
cv2.imshow('Output Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
