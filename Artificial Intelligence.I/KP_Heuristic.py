import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


# def dfs(num, vertix, visited, paths, curr_path, curr_weight):
#     if all(visited):
#         print(curr_weight, curr_path)

#     for u, w in graph[vertix]:
#         if not visited[u]:
#             visited[u] = True
#             curr_path.append(u)
#             curr_weight += w
#             dfs(graph, u, visited, paths, curr_path, curr_weight)
#             visited[u] = False
#             curr_path.pop()
#             curr_weight -= w


# def traveling_salesman_dfs(num):
#     paths = []
#     curr_path = []
#     curr_weight = 0
#     vertix = 0
#     visited = [False for i in range(len(num))]
#     curr_path.append(vertix)
#     visited[vertix] = True
#     dfs(num, vertix, visited, paths, curr_path, curr_weight)
#     # print(paths)

#     rec_path, min_weight = paths[0]
#     for l, w in paths:
#         if w < min_weight:
#             rec_path = l
#             min_weight = w

#     return min_weight, rec_path


max_weight = int(input("Enter Max weight of Knapsack: "))
num_items = int(input("Enter Number of items: "))

items = []
print("Enter List of iterm: ")
for _ in range(num_items):
    item_weigth, item_cost = map(int, input().split())
    items.append((item_weigth, item_cost))

items.sort(reverse=True, key=lambda x: x[1]/x[0])
# print(items)


# def knapsack_heuristic(values, weights, capacity):
#     n = len(values)
#     value_density = [(values[i] / weights[i], i) for i in range(n)]
#     value_density.sort(reverse=True)
#     print(value_density)
#     total_value = 0
#     total_weight = 0
#     selected_items = []
#     for vd, i in value_density:
#         if total_weight + weights[i] <= capacity:
#             total_weight += weights[i]
#             total_value += values[i]
#             selected_items.append(i)
#     return total_value, selected_items


# max_weight = int(input("Enter Max weight of Knapsack: "))
# num_items = int(input("Enter Number of items: "))
# weights = [int(num) for num in input("Enter a list of weigths:").split()]
# values = [int(num) for num in input("Enter a list of costs:").split()]
# print("Total Cost and List of items are: ")
# print(knapsack_heuristic(values, weights, max_weight))
