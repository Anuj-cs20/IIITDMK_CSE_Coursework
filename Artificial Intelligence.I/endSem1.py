def align(seq1, seq2):
    # initialize the starting node
    start = Node(0, 0, [], heuristic(seq1, seq2, 0, 0))

    # initialize the priority queue
    queue = [start]

    # initialize the set of visited nodes
    visited = set()

    # while the queue is not empty
    while queue:
        # get the node with the lowest total cost
        node = min(queue, key=lambda x: x.total_cost)

        # remove the node from the queue
        queue.remove(node)

        # if the node represents the end of the sequences, return the path
        if node.i == len(seq1) and node.j == len(seq2):
            return node.path

        # if the node has not been visited
        if (node.i, node.j) not in visited:
            # mark the node as visited
            visited.add((node.i, node.j))

            # generate the children of the node
            children = []

            # generate the child that represents an insertion in seq1
            if node.i < len(seq1):
                cost = node.cost + 1
                h = heuristic(seq1, seq2, node.i + 1, node.j)
                child = Node(node.i + 1, node.j, node.path +
                             [('Insert', seq1[node.i])], cost + h)
                children.append(child)

            # generate the child that represents a deletion in seq1
            if node.j < len(seq2):
                cost = node.cost + 1
                h = heuristic(seq1, seq2, node.i, node.j + 1)
                child = Node(node.i, node.j + 1, node.path +
                             [('Delete', seq2[node.j])], cost + h)
                children.append(child)

            # generate the child that represents a substitution
            if node.i < len(seq1) and node.j < len(seq2):
                cost = node.cost + (seq1[node.i] != seq2[node.j])
                h = heuristic(seq1, seq2, node.i + 1, node.j + 1)
                child = Node(node.i + 1, node.j + 1, node.path +
                             [('Substitute', seq1[node.i], seq2[node.j])], cost + h)
                children.append(child)

            # add the children to the queue
            queue.extend(children)

    # if no path was found, return None
    return None


def heuristic(seq1, seq2, i, j):
    return sum(seq1[k] != seq2[l] for k in range(i, len(seq1)) for l in range(j, len(seq2)))


class Node:
    def __init__(self, i, j, path, total_cost):
        self.i = i
        self.j = j
        self.path = path
        self.cost = len(path)
        self.total_cost = total_cost

    def __lt__(self, other):
        return self.total_cost < other.total_cost


seq2 = "AGCT"
seq1 = "GATC"

operations = (align(seq1, seq2))
print(operations)
min_cost = 0
for i in range(len(operations)):
    for j in range(1):
        if (operations[i][0] == 'Substitute'):
            if operations[i][1] == operations[i][2]:
                min_cost = min_cost
            else:
                min_cost += 1
        else:
            min_cost += 1

print(min_cost)
