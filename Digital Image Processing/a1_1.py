import cv2
import numpy as np
image = cv2.imread('./Lena.png')

# normalized Image - pixels range [0,1]
ima = (image - np.min(image)) / (np.max(image) - np.min(image))
cv2.imshow('Orginal Image', ima)
cv2.waitKey(0)

(row, col) = image.shape[0:2]
# Take the average of pixel values of the BGR Channels
# to convert the colored image to grayscale image
for i in range(row):
    for j in range(col):
        # Find the average of the BGR pixel values
        image[i, j] = sum(image[i, j]) * 0.33

cv2.imshow('Gray Image', image)
cv2.waitKey(0)

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow('Orginal Image', gray_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

'''
    There are several methods for scaling an image, including:
    Interpolation: This method involves adding or removing pixels to increase or decrease the resolution of the image. The most commonly used interpolation methods are nearest-neighbor, bilinear, and bicubic interpolation.
    Resampling: This method changes the resolution of an image by adjusting the spacing between pixels. This can be done by either downsampling or upsampling the image.
    Image pyramids: This method involves creating a series of images at different scales, usually by repeatedly reducing the resolution of the original image.
    Re-sizing: This method involves changing the size of an image by adjusting the number of pixels. This can be done by either upsizing or downsizing the image.
    Transforming: This method involves geometric transformation such as rotation, shearing, and perspective transformation.
    Seam carving: is a content-aware image resizing technique where the image is reduced in size by one pixel of height (or width) at a time.
'''


