nodes = int(input("Enter number of nodes: "))
edges = int(input("Enter number of edges: "))

matrix = [[0 for i in range(nodes)] for j in range(nodes)]


for i in range(edges):
    node1 = int(input("Enter node-1 number: "))
    node2 = int(input("Enter node-2 number: "))
    print()
    matrix[node1][node2] = 1

print(matrix)

visited = []
queue = [] 


def bfs(visited, matrix, node):
  visited.append(node)
  queue.append(node)

  while queue:
    s = queue.pop(0)
    print(s, end=" ")

    for neighbour in range(nodes):
        if matrix[s][neighbour] == 1:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


bfs(visited, matrix, 0)

