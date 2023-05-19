from sys import maxsize
from itertools import permutations

def tsp(g, s):
    uv = []
    for i in range(n):
        if i != s:
            uv.append(i)

    min_path = maxsize
    paths = permutations(uv)
    # print(paths)
    for path in paths:
        curr_path = 0
        i = s
        for j in path:
            curr_path += g[i][j]
            i = j
        curr_path += g[i][s]
        min_path = min(min_path,curr_path)

    return min_path



n = int(input("Enter number of nodes: "))
graph = [[0 for i in range(n)] for j in range(n)]

print("Enter weight of the edge between node")
for i in range(n):
    for j in range(i):
        graph[i][j] = int(input(f"{j + 1} - {i + 1}: "))
        graph[j][i] = graph[i][j]

# print(graph)
print(f"Minimum path weight/distance: {tsp(graph, 0)}")
