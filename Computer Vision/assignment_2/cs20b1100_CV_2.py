import cv2

image_path = "./cs20b1100.png"
original_image = cv2.imread(image_path, cv2.IMREAD_COLOR)
cv2.imshow('Original Image', original_image)


def addEdge(c, edge_image):
    scaled_resultant_image = cv2.convertScaleAbs(edge_image * c)

    # Add the scaled resultant image to the original image
    final_image = cv2.addWeighted(original_image, 1, cv2.cvtColor(
        scaled_resultant_image, cv2.COLOR_GRAY2BGR), 1, 0)

    return final_image


canny_edge_image = cv2.Canny(original_image, 100, 200)
cv2.imshow('Canny Edge Image', canny_edge_image)

# Multiply the Canny edge image by a constant 'c'
c = 0.15
canny_sharp_image = addEdge(c, canny_edge_image)
cv2.imshow('Sharpen Image with Canny Edge Image', canny_sharp_image)

gray_image = cv2.cvtColor(original_image, cv2.COLOR_BGR2GRAY)
laplacian_image = cv2.Laplacian(gray_image, cv2.CV_64F)
marr_hildreth_edge_image = cv2.convertScaleAbs(laplacian_image)
cv2.imshow('Marr Hildreth Edge Image', marr_hildreth_edge_image)

c = 0.7
marr_hildreth_sharp_image = addEdge(c, marr_hildreth_edge_image)
cv2.imshow('Sharpen Image with Marr Hildreth Edge Image',
           marr_hildreth_sharp_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
