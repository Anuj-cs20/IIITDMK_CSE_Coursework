# Anuj.K
# CS20B1100

import numpy as np
import matplotlib.pyplot as plt


w1 = np.array([[2, 6], [3, 4], [3, 8], [4, 6]])
w2 = np.array([[3, 0], [1, -2], [3, -4], [5, -2]])

mean1 = np.mean(w1, axis=0)
mean2 = np.mean(w2, axis=0)

cov1 = np.cov(w1.transpose())
cov2 = np.cov(w2.transpose())

inv_cov1 = np.linalg.inv(cov1)
inv_cov2 = np.linalg.inv(cov2)

comparison = (cov1 == cov2)
if (not comparison.all()):
    print("It's Case 3")
else:
    if ((cov1[0][0] == cov1[1][1]) and (cov1[0][1] == 0) and (cov1[1][0] == 0)):
        print("It's Case 1")
    else:
        print("It's Case 2")


a1 = -0.5 * inv_cov1
a2 = -0.5 * inv_cov2

b1 = inv_cov1 @ mean1
b2 = inv_cov2 @ mean2

c1 = -0.5*(mean1.transpose() @ inv_cov1 @ mean1) - 0.5 * \
    (np.log(np.linalg.det(inv_cov1))) + np.log(0.5)
c2 = -0.5*(mean2.transpose() @ inv_cov2 @ mean2) - 0.5 * \
    (np.log(np.linalg.det(inv_cov2))) + np.log(0.5)

a = a1 - a2
b = (b1 - b2).transpose()
c = c1 - c2

print("The Decision Boundary equation is:")
print(f"{a[0][0]} * x^2 + {b[0]} * x + {b[1]} * y + {c} = 0")

fig, ax = plt.subplots(1, 1, figsize=(10, 7), tight_layout=True)
x1 = w1[:, 0]
y1 = w1[:, 1]
x2 = w2[:, 0]
y2 = w2[:, 1]
x = np.linspace(-3, 7, 20)
y = ((-a[0][0] / b[1]) * (x**2)) + ((-b[0] / b[1]) * x) + (-c / b[1])
ax.plot(x, y)

ax.scatter(x1, y1, color="red", label="w1")
ax.scatter(x2, y2, color="green", label="w2")

plt.title("Decision boundary separating the 2 classes", fontsize=18)
plt.legend()
plt.show()
