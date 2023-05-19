import numpy as np
import matplotlib.pyplot as plt
import cv2

q = cv2.imread("queryimage.png")
r1 = cv2.imread("refimage1.png")
r2 = cv2.imread("refimage2.png")
q = cv2.cvtColor(q, cv2.COLOR_BGR2RGB)
r1 = cv2.cvtColor(r1, cv2.COLOR_BGR2RGB)
r2 = cv2.cvtColor(r2, cv2.COLOR_BGR2RGB)

plt.subplot(1, 3, 1)
plt.imshow(q)
plt.title("Query Image")
plt.subplot(1, 3, 2)
plt.imshow(r1)
plt.title("Reference Image 1")
plt.subplot(1, 3, 3)
plt.imshow(r2)
plt.title("Reference Image 2")
plt.show()

q_hist = cv2.calcHist([q], [0], None, [256], [0, 256])
r1_hist = cv2.calcHist([r1], [0], None, [256], [0, 256])
r2_hist = cv2.calcHist([r2], [0], None, [256], [0, 256])

plt.plot(q_hist)
plt.title("Query Image Histogram")
plt.show()

plt.plot(r1_hist)
plt.title("Reference Image 1 Histogram")
plt.show()

plt.plot(r2_hist)
plt.title("Reference Image 2 Histogram")
plt.show()


def bhattacharyyaDistance(H1, H2):
    return -np.log(np.sum(np.sqrt(H1*H2)))


q_hist = q_hist/np.sum(q_hist)
r1_hist = r1_hist/np.sum(r1_hist)
r2_hist = r2_hist/np.sum(r2_hist)

r1_distance = bhattacharyyaDistance(q_hist, r1_hist)
print("The distance between query image and reference image 1 using bhattacharyya distance is ", r1_distance)

r2_distance = bhattacharyyaDistance(q_hist, r2_hist)
print("The distance between query image and reference image 2 using bhattacharyya distance is ", r2_distance)
