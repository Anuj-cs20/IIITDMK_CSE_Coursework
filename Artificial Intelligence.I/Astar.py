import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


import heapq
import math
from collections import defaultdict


def create_MST(graph, start):
    visited = set()
    edges = []
    heap = [(0, start, None)]
    while heap:
        (cost, current, parent) = heapq.heappop(heap)
        if current in visited:
            continue
        visited.add(current)
        if parent is not None:
            edges.append((parent, current, cost))
        for neighbor, cost in graph[current]:
            if neighbor not in visited:
                heapq.heappush(heap, (cost, neighbor, current))
    return edges


def create_heuristics(graph, mst):
    heuristics = {}
    for node in graph.keys():
        heuristics[node] = mst[start][node]
    return heuristics


def Astar(graph, start):
    mst = create_MST(graph, start)
    heuristics = create_heuristics(graph, mst)
    visited = set()
    heap = [(0, start, None, [start])]
    while heap:
        (cost, current, parent, path) = heapq.heappop(heap)
        if current in visited:
            continue
        visited.add(current)
        if len(visited) == len(graph):
            return path
        for neighbor, cost in graph[current]:
            if neighbor not in visited:
                heapq.heappush(
                    heap, (cost + heuristics[neighbor] - heuristics[current], neighbor, current, path + [neighbor]))


graph = {0: [(1, 12), (2, 10), (3, 19), (4, 8)],
         1: [(0, 12), (2, 3), (3, 7), (4, 6)],
         2: [(0, 10), (1, 3), (3, 2), (4, 20)],
         3: [(0, 19), (1, 7), (2, 2), (4, 4)],
         4: [(0, 8), (1, 6), (2, 20), (3, 4)],
         }
start = 0
path = Astar(graph, start)
print("Path:", path)
