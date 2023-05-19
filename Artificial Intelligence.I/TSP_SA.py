# import random
import numpy as np
import matplotlib.pyplot as plt

num_cities = 15
grid_size = 10
cities = np.random.randint(low=0, high=grid_size, size=(num_cities, 2))

distances = np.zeros((num_cities, num_cities))
for i in range(num_cities):
    for j in range(num_cities):
        distances[i, j] = np.linalg.norm(cities[i] - cities[j])

start_city = np.random.randint(num_cities)

print("Initial Path: \n", cities)
plt.scatter(cities[:, 0], cities[:, 1])
plt.plot(cities[:, 0][np.concatenate((np.arange(start_city, num_cities), np.arange(start_city)))],
         cities[:, 1][np.concatenate((np.arange(start_city, num_cities), np.arange(start_city)))])
plt.title('Initial Path')
plt.show()


def simulated_annealing(distances, start_city, temp_start, cooling_factor):
    num_cities = len(distances)
    path = np.arange(num_cities)
    np.random.shuffle(path)
    current_cost = 0
    for i in range(num_cities):
        current_cost += distances[path[i-1], path[i]]
    current_path = np.copy(path)
    current_temp = temp_start
    costs = []
    while current_temp > 1e-10:
        for i in range(num_cities):
            # Generate a random neighbor by swapping two cities
            j, k = np.random.randint(num_cities, size=2)
            new_path = np.copy(current_path)
            new_path[j], new_path[k] = new_path[k], new_path[j]
            # Calculate the cost of the new path
            new_cost = 0
            for l in range(num_cities):
                new_cost += distances[new_path[l-1], new_path[l]]
            # Decide whether to accept the neighbor
            delta_cost = new_cost - current_cost
            if delta_cost < 0 or np.exp(-delta_cost / current_temp) > np.random.rand():
                current_path = np.copy(new_path)
                current_cost = new_cost
        current_temp *= cooling_factor
        costs.append(current_cost)
    return current_path, current_cost, costs


# Run simulated annealing
temp_start = 1e+10
cooling_factor = 0.97
path, cost, costs = simulated_annealing(
    distances, start_city, temp_start, cooling_factor)

# Plot iteration vs cost graph
plt.plot(costs)
plt.title('Iteration vs Cost')
plt.show()

# Plot final solution
print("Final Path: \n", cities)
print("Cost: ", cost)
plt.scatter(cities[:, 0], cities[:, 1])
plt.plot(cities[path, 0], cities[path, 1])
plt.title('Final Solution (cost={:.2f})'.format(cost))
plt.show()
