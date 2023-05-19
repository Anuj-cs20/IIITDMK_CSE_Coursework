import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

# Input
# 5
# 0 1 12
# 0 2 10
# 0 3 19
# 0 4 8
# 1 2 3
# 1 3 7
# 1 4 6
# 2 3 2
# 2 4 20
# 3 4 4


def traveling_salesman_ids(graph):
    start = 0

    def dfs(graph, start, depth, visited, path, cost):
        if depth == depth_limit:
            return sys.maxsize, []

        if all(visited):
            return cost + graph[start][0][1], path

        rec_cost = sys.maxsize
        rec_path = []

        for neighbor, cost_neighbor in graph[start]:
            if visited[neighbor]:
                continue

            visited[neighbor] = True
            new_cost, new_path = dfs(
                graph, neighbor, depth + 1, visited, path + [neighbor], cost + cost_neighbor)
            visited[neighbor] = False

            if new_cost < rec_cost:
                rec_cost = new_cost
                rec_path = new_path

        return rec_cost, rec_path

    for depth_limit in range(len(graph)+1):
        visited = [False for _ in range(len(graph))]
        visited[start] = True
        result = dfs(graph, start, 0, visited, [start], 0)
        if result[0] != sys.maxsize:
            return result

    return sys.maxsize, []


def traveling_salesman_bfs(graph):
    l = []
    start = 0
    l.append(start)
    queue = [(l, 0)]
    paths = []

    while queue:
        curr_path, curr_cost = queue.pop(0)
        if len(curr_path) == len(graph):
            curr_cost += graph[curr_path[-1]][0][1]
            paths.append((curr_path, curr_cost))

        for neighbor, cost in graph[curr_path[-1]]:
            if neighbor not in curr_path:
                queue.append((curr_path + [neighbor], curr_cost+cost))

    # print(paths)

    rec_path, min_weight = paths[0]
    for l, w in paths:
        if w < min_weight:
            rec_path = l
            min_weight = w

    return min_weight, rec_path


def dfs(graph, vertix, visited, paths, curr_path, curr_weight):
    if all(visited):
        curr_weight += graph[vertix][0][1]
        c_path = curr_path[:]
        paths.append((c_path, curr_weight))

    for u, w in graph[vertix]:
        if not visited[u]:
            visited[u] = True
            curr_path.append(u)
            curr_weight += w
            dfs(graph, u, visited, paths, curr_path, curr_weight)
            visited[u] = False
            curr_path.pop()
            curr_weight -= w


def traveling_salesman_dfs(graph):
    paths = []
    curr_path = []
    curr_weight = 0
    vertix = 0
    visited = [False for i in range(len(graph))]
    curr_path.append(vertix)
    visited[vertix] = True
    dfs(graph, vertix, visited, paths, curr_path, curr_weight)
    # print(paths)

    rec_path, min_weight = paths[0]
    for l, w in paths:
        if w < min_weight:
            rec_path = l
            min_weight = w

    return min_weight, rec_path


def read_weighted_graph():
    n = int(input())
    m = n*(n-1)//2
    graph = {}
    for i in range(n):
        graph[i] = []
    for i in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        graph[v].append((u, w))
    return graph


graph = read_weighted_graph()
# print(graph)

min_cost, path = traveling_salesman_dfs(graph)
print("Depth First Search")
print("Minimum Cost:", min_cost)
print("Path:", path)
print()

min_cost, path = traveling_salesman_bfs(graph)
print("Breadth-First Search")
print("Minimum Cost:", min_cost)
print("Path:", path)
print()

min_cost, path = traveling_salesman_ids(graph)
print("Iterative Deepening Search")
print("Minimum Cost:", min_cost)
print("Path:", path)
print()
