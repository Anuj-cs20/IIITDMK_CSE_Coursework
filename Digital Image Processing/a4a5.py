import cv2
import numpy as np

# Assignment 4
pisa = cv2.imread('PISA.jpg')
height, width = pisa.shape[:2]
angle = 11
rotation_matrix = cv2.getRotationMatrix2D((width/2, height/2), angle, 1)
rotated_pisa = cv2.warpAffine(pisa, rotation_matrix, (width, height))
cv2.imshow('Original Image', pisa)
cv2.imshow('Rotated Image', rotated_pisa)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Assignment 5
img = cv2.imread("pout-dark.jpg", 0)
equ = cv2.equalizeHist(img)
cv2.imshow("pout-dark Image", img)
cv2.imshow("Image After Histograms Equalization", equ)
cv2.waitKey(0)
orginal = cv2.imread("pout-dark.jpg", 0)
ref_image = cv2.imread("pout-bright.jpg", 0)
final = cv2.equalizeHist(orginal,ref_image)
cv2.imshow("Orginal Image", img)
cv2.imshow('Orginal-After Histogram Matching', final)
cv2.waitKey(0)
cv2.destroyAllWindows()
