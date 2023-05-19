import random
import math
import matplotlib.pyplot as plt

# Generate random 2D points
n_cities = 15
cities = [(random.randint(0, 10), random.randint(0, 10))
          for i in range(n_cities)]

# Calculate Euclidean distance between two points


def distance(p1, p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

# Calculate total distance of a path


def total_distance(path):
    dist = 0
    for i in range(len(path)-1):
        dist += distance(cities[path[i]], cities[path[i+1]])
    dist += distance(cities[path[-1]], cities[path[0]])
    return dist


# Initialize a random path
path = list(range(n_cities))
random.shuffle(path)

# Plot initial path
fig, ax = plt.subplots()
ax.set_aspect('equal')
ax.scatter([city[0] for city in cities], [city[1] for city in cities])
for i in range(n_cities-1):
    ax.plot([cities[path[i]][0], cities[path[i+1]][0]],
            [cities[path[i]][1], cities[path[i+1]][1]], color='b')
ax.plot([cities[path[-1]][0], cities[path[0]][0]],
        [cities[path[-1]][1], cities[path[0]][1]], color='b')
plt.title('Initial path')
plt.show()

# Simulated Annealing algorithm
T = 1e+10
T_min = 1
cooling_factor = 0.97
path_best = path.copy()
cost_best = total_distance(path_best)
costs = [cost_best]

while T > T_min:
    for i in range(100):
        # Generate a new candidate path by swapping two random cities
        path_new = path.copy()
        i, j = random.sample(range(n_cities), 2)
        path_new[i], path_new[j] = path_new[j], path_new[i]

        # Calculate the cost of the new path
        cost_new = total_distance(path_new)

        # Accept the new path with a probability based on the current temperature and cost difference
        delta_cost = cost_new - cost_best
        if delta_cost < 0 or math.exp(-delta_cost/T) > random.uniform(0, 1):
            path = path_new
            cost_best = cost_new
            if cost_best < total_distance(path_best):
                path_best = path.copy()
                costs.append(cost_best)

    T *= cooling_factor

# Plot final path
fig, ax = plt.subplots()
ax.set_aspect('equal')
ax.scatter([city[0] for city in cities], [city[1] for city in cities])
for i in range(n_cities-1):
    ax.plot([cities[path_best[i]][0], cities[path_best[i+1]][0]],
            [cities[path_best[i]][1], cities[path_best[i+1]][1]], color='r')
ax.plot([cities[path_best[-1]][0], cities[path_best[0]][0]],
        [cities[path_best[-1]][1], cities[path_best[0]][1]], color='r')
plt.title('Final path')
plt.show()

# Plot iteration vs cost graph
plt.plot(range(len(costs)), costs)
plt.xlabel('Iteration')
plt.ylabel('Cost')
plt.title('SA optimization')
plt.show()
