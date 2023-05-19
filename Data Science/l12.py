import numpy as np
import matplotlib.pyplot as plt
# from scipy.stats import bernoulli
import scipy.stats as sts

m_exp = list()
m_u = list()
m_ber = list()
para = [10, 100, 500, 1000, 5000, 10000, 50000]

x = np.arange(len(para))

plt.xticks(x, para)

for m in para:
    d_exp = sts.expon.rvs(scale=10, size=m)
    d_exp = np.round(d_exp, decimals=2)
    mean = sum(d_exp)/len(d_exp)
    m_exp.append(mean)

    d_u = sts.uniform.rvs(size=m)
    d_u = np.round(d_u, decimals=2)
    mean = sum(d_u)/len(d_u)
    m_u.append(mean)

    d_ber = sts.bernoulli.rvs(size=m, p=0.4)
    d_ber = np.round(d_ber, decimals=2)
    mean = sum(d_ber)/len(d_ber)
    m_ber.append(mean)

plt.bar(x, m_exp)
plt.bar(x, m_u)
plt.bar(x, m_ber)
plt.show()

# x = [10, 100, 500, 1000, 5000, 10000, 50000]

# Exponential = []
# Uniform = []
# Bernoulli = []

# exponentialMean = []
# uniformMean = []
# bernoulliMean = []

# for a in x:
#     np1 = np.random.exponential(3.45, a)
#     np1 = np.round(np1, 1)
#     Exponential.append(np1)

#     np2 = np.random.uniform(0, 100, a)
#     np2 = np.round(np2, 1)
#     Uniform.append(np2)

#     np3 = bernoulli.rvs(0.3, size=a)
#     np3 = np.round(np3, 1)
#     Bernoulli.append(np3)

# for a in range(7):
#     exponentialMean.append(np.mean(Exponential[a]))
#     uniformMean.append(np.mean(Uniform[a]))
#     bernoulliMean.append(np.mean(Bernoulli[a]))

# # print("Mean for Exponential Distribution")
# # print(exponentialMean)
# # print("Mean for Uniform Distribution")
# # print(uniformMean)
# # print("Mean for Bernoulli Distribution")
# # print(bernoulliMean)

# plt.title("Exponential Distribution")
# plt.xlabel("Sample size")
# plt.ylabel("Mean")
# plt.plot(x, exponentialMean)
# plt.show()

# plt.title("Uniform Distribution")
# plt.xlabel("Sample size")
# plt.ylabel("Mean")
# plt.plot(x, uniformMean)
# plt.show()

# plt.title("Bernoulli Distribution")
# plt.xlabel("Sample size")
# plt.ylabel("Mean")
# plt.plot(x, bernoulliMean)
# plt.show()

l1 = []
l2 = []
l3 = []

sizes = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096]
exp = np.random.exponential(5, 10000)
uni = np.random.uniform(0, 1, 10000)
ber = np.random.binomial(1, 0.6, 10000)

for i in sizes:
    j = 0
    for j in range(0, i):
        arr = np.random.choice(exp, 1000)
        mean = arr.mean()
        l1.append(mean)
    plt.hist(l1)
    plt.title("Exponential Distribution for Central Limit theorem")
    plt.show()
    l1.clear()

for i in sizes:
    j = 0
    for j in range(0, i):
        arr = np.random.choice(uni, 1000)
        mean = arr.mean()
        l2.append(mean)
    plt.hist(l2)
    plt.title("Uniform Distribution for Central Limit theorem")
    plt.show()
    l2.clear()

for i in sizes:
    j = 0
    for j in range(0, i):
        arr = np.random.choice(ber, 1000)
        mean = arr.mean()
        l3.append(mean)
    plt.hist(l3)
    plt.title("Bernoulli Distribution for Central Limit theorem")
    plt.show()
    l3.clear()
