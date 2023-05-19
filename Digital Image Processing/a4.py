import math
import matplotlib.pyplot as plt
import numpy as np
import cv2


def bilinear_resizing(image, angle, scaleX, scaleY):
    angle = angle*(math.pi/180)
    print("angle", angle)
    print("old shape", image.shape)
    img_height, img_width, img_depth = image.shape[:3]

    new_height = int(math.ceil(img_height*scaleY))
    new_width = int(math.ceil(img_width * scaleX))
    resized = np.empty((new_height, new_width, img_depth), int)
    # print(resized)
    oldCenter = [img_height/2, img_width/2]
    print("old center", oldCenter)
    print("new shape", resized.shape)
    newCenter = [new_height/2, new_width/2]
    print("new center", newCenter)
    x = 5
    for i in range(new_height):
        for j in range(new_width):
            # change of axis
            y = i
            x = j

            y -= newCenter[0]
            x -= newCenter[1]

            y = y*(img_height-1)/(new_height-1)
            x = x*(img_width-1)/(new_width-1)

            valueX = x*math.cos(angle) + y*math.sin(angle)
            valueY = -x*math.sin(angle) + y*math.cos(angle)

            valueY += oldCenter[0]
            valueX += oldCenter[1]

            aY = math.floor(valueY)
            bY = math.ceil(valueY)
            daY = valueY - math.floor(valueY)
            dbY = math.ceil(valueY) - valueY

            aX = math.floor(valueX)
            bX = math.ceil(valueX)
            daX = valueX - math.floor(valueX)
            dbX = math.ceil(valueX) - valueX

            pixel = []
            if (aY >= img_height or bY >= img_height or aX >= img_width or bX >= img_width
               or aY < 0 or bY < 0 or aX < 0 or bX < 0):
                pixel = [0, 0, 0]
                resized[i][j] = pixel
                continue
            # to change rgb to bgr
            # print(aX,aY,bX,bY)
            run = [2, 1, 0]
            for k in run:
                pixel.append(dbX*dbY*image[aY][aX][k] + daX*daY*image[bY][bX]
                             [k] + daX*dbY*image[aY][bX][k] + dbX*daY*image[bY][aX][k])
            resized[i][j] = pixel

            pixel = []
            if (aY == bY and aX == bX):
                for k in run:
                    pixel.append(image[aY][aX][k])
                resized[i][j] = pixel
            elif (aY == bY):
                for k in run:
                    pixel.append(dbX*image[aY][aX][k] + daX*image[aY][bX][k])
                resized[i][j] = pixel
            elif (aX == bX):
                for k in run:
                    pixel.append(dbY*image[aY][aX][k] + daY*image[bY][aX][k])
                resized[i][j] = pixel
    return resized


def gradient_intensity(img):
    # Convert the image to grayscale
    img = img.astype(np.uint8)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Define the Sobel kernels
    sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    sobel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

    # Calculate the gradient of intensity
    grad_x = np.zeros(gray.shape)
    grad_y = np.zeros(gray.shape)

    for i in range(1, gray.shape[0] - 1):
        for j in range(1, gray.shape[1] - 1):
            grad_x[i, j] = np.sum(np.multiply(gray[i-1:i+2, j-1:j+2], sobel_x))
            grad_y[i, j] = np.sum(np.multiply(gray[i-1:i+2, j-1:j+2], sobel_y))

    grad_magnitude = np.sqrt(np.square(grad_x) + np.square(grad_y))

    return grad_magnitude


img = cv2.imread("PISA.jpg")
rotatedImg = bilinear_resizing(img, -11, 1, 1)
plt.imshow(rotatedImg)


x = gradient_intensity(rotatedImg)
plt.imshow(x)
