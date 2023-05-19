# Anuj.K
# CS20B1100

import numpy as np
import matplotlib.pyplot as plt

w1 = np.array([[1, 6], [3, 4], [3, 8], [5, 6]])
w2 = np.array([[3, 0], [1, -2], [3, -4], [5, -2]])

mean1 = np.mean(w1, axis=0)
mean2 = np.mean(w2, axis=0)

cov1 = np.cov(w1.transpose())
cov2 = np.cov(w2.transpose())

inv_cov1 = np.linalg.inv(cov1)
inv_cov2 = np.linalg.inv(cov2)

if (cov1.all() != cov2.all()):
    print("It's Case 3")
else:
    if ((cov1[0][0] == cov1[1][1]) and (cov1[0][1] == 0) and (cov1[1][0] == 0)):
        print("It's Case 1")
    else:
        print("It's Case 2")

sigma_sq = cov1[0][0]
mean1 = mean1.reshape(1, 2)
mean2 = mean2.reshape(1, 2)
avg_mean = 0.5 * (mean1 + mean2)
x0 = avg_mean

omega_transpose = (mean1-mean2).transpose()
# print(omega_transpose)

temp = omega_transpose @ x0
# print(temp)

print(f"The Decision Boundary is y = {((temp[1][1]) / omega_transpose[1])[0]}")

fig, ax = plt.subplots(1, 1, figsize=(10, 7), tight_layout=True)
x1 = w1[:, 0]
y1 = w1[:, 1]
x2 = w2[:, 0]
y2 = w2[:, 1]
x = np.linspace(-2, 6, 10)
y = x*0 + (temp[1][1] / omega_transpose[1])
ax.plot(x, y)

ax.plot(3, 2, 'bo', label='Intersection Point')
ax.scatter(x1, y1, color="red", label="w1")
ax.scatter(x2, y2, color="green", label="w2")

plt.title("Decision boundary separating the 2 classes", fontsize=18)
plt.legend()
plt.show()
