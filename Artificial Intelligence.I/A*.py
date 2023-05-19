import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

import heapq


def Astar_TSP_MST(graph, heuristics):
    start = 0
    OPENED = [(0, start, [start])]
    visited = set()

    while OPENED:
        # Get the node with the lowest f value (sum of g and h)
        (f, current_node, path) = heapq.heappop(OPENED)

        # If all nodes have been visited, return the path
        if len(path) == len(graph):
            path.append(0)
            return path

        # If the current node has been visited, skip it
        if current_node in visited:
            continue

        # Mark the current node as visited
        visited.add(current_node)

        # Loop through the neighbors of the current node
        for neighbor, g in graph[current_node]:
            if neighbor not in visited:
                h = heuristics[neighbor]
                f = g + h
                heapq.heappush(OPENED, (f, neighbor, path + [neighbor]))

    return None


def minimumSpanningTree(graph, node):
    if node == 0:
        node1 = 1
    else:
        node1 = 0

    S = []
    cost = 0
    S.append(node1)
    while len(S) != len(graph) - 1:
        min = sys.maxsize
        for neighbor, weight in graph[S[-1]]:
            if neighbor not in S and neighbor != node and min > weight:
                node1 = neighbor
                min = weight
        S.append(node1)
        cost += min
    return cost


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
print("Graph: ")
print(graph)
heuristic_values = [minimumSpanningTree(graph, i) for i in range(len(graph))]
print()
print("Heuristics: ")
print(heuristic_values)
path = Astar_TSP_MST(graph, heuristic_values)
print()
print("TSP with Astar: ")
print("Path:", path)
cost = 0
if path != None:
    for i in range(len(path)-1):
        for n in graph[path[i]]:
            if n[0] == path[i+1]:
                cost += n[1]
    print("Cost", cost)
