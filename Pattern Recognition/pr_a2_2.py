# Anuj.K
# CS20B1100

import numpy as np
import matplotlib.pyplot as plt

w1 = np.array([[1, -1], [2, -5], [3, -6], [4, -10], [5, -12], [6, -15]])
w2 = np.array([[-1, 1], [-2, 5], [-3, 6], [-4, 10], [-5, 12], [-6, 15]])

mean1 = np.mean(w1, axis=0)
mean2 = np.mean(w2, axis=0)

cov1 = np.cov(w1.transpose())
cov2 = np.cov(w2.transpose())

inv_cov1 = np.linalg.inv(cov1)
inv_cov2 = np.linalg.inv(cov2)

if (cov1.all() != cov2.all()):
    print("It's Case 3")
else:
    print("It's Case 2")

p1 = 0.3
p2 = 0.7
avg_mean = 0.5 * (mean1 + mean2)
x0 = avg_mean - \
    [[np.log(p1/p2) / ((mean1-mean2).transpose()
                       @ inv_cov1 @ (mean1-mean2))] * (mean1-mean2)]

omega_transpose = (inv_cov1 @ (mean1-mean2)).transpose()
# print(omega_transpose)

ot = omega_transpose.reshape(2, 1)

temp = ot @ x0
# print(temp)

print(
    f"Intersection Point (x,y) = ({(temp[0][0] / ot[0])[0]},{(temp[0][1] / ot[0])[0]})")
print(
    f"The Decision Boundary is : y = -{(ot[0] / ot[1])[0]} * x + {((temp[0][0] + temp[1][1]) / ot[1])[0]}")

fig, ax = plt.subplots(1, 1, figsize=(10, 7), tight_layout=True)
x1 = w1[:, 0]
y1 = w1[:, 1]
x2 = w2[:, 0]
y2 = w2[:, 1]
x = np.linspace(-10, 10, 20)
y = -3 * x + 0.12104255
ax.plot(x, y)

ax.plot(0.18156383, -0.42364893, 'bo', label='Intersection Point')
ax.scatter(x1, y1, color="red", label="w1")
ax.scatter(x2, y2, color="green", label="w2")

plt.title("Decision boundary separating the 2 classes", fontsize=18)
plt.legend()
plt.show()
