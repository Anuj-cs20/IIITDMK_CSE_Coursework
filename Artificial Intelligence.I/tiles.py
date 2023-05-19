import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''
INPUT: 
Enter Initial State: 
2 8 3
1 6 4
7 _ 5

Enter Final State: 
1 2 3
8 _ 4
7 6 5

OUTPUT: 
The Astar_Tiles_misplaced took 6.413459777832031e-05 seconds to run.
Number of Moves required to reach final state: 5
Path: 
2 8 3 
1 6 4 
7 _ 5 

2 8 3 
1 _ 4 
7 6 5 

2 _ 3 
1 8 4 
7 6 5 

_ 2 3 
1 8 4 
7 6 5 

1 2 3 
_ 8 4 
7 6 5 

1 2 3 
8 _ 4 
7 6 5 

The Astar_Tiles_distance took 6.079673767089844e-05 seconds to run.
Number of Moves required to reach final state: 5
Path: 
2 8 3 
1 6 4 
7 _ 5 

2 8 3 
1 _ 4 
7 6 5 

2 _ 3 
1 8 4 
7 6 5 

_ 2 3 
1 8 4 
7 6 5 

1 2 3 
_ 8 4 
7 6 5 

1 2 3 
8 _ 4 
7 6 5 

'''

import heapq
import time


def printTiles(currState):
    for x in range(3):
        for y in range(3):
            print(currState[x][y], end=' ')
        print()


def misplacedTiles(currState, finalState):
    count = 0
    for x in range(3):
        for y in range(3):
            if not currState[x][y] == '_' and not finalState[x][y] == '_':
                if currState[x][y] != finalState[x][y]:
                    count += 1
    return count


def manhattan_distance(currState, finalState):
    distance = 0
    for i in range(len(currState)):
        for j in range(len(currState[0])):
            if currState[i][j] != finalState[i][j] and currState[i][j] != '_':
                curr_row, curr_col = i, j
                final_row, final_col = 0, 0
                for k in range(len(finalState)):
                    if currState[i][j] in finalState[k]:
                        final_row = k
                        final_col = finalState[k].index(currState[i][j])
                        break
                distance += abs(curr_row - final_row) + \
                    abs(curr_col - final_col)
    return distance


def neighbors(currState):
    r, c = 0, 0
    for x in range(3):
        for y in range(3):
            if currState[x][y] == '_':
                r, c = x, y
                break

    neighbors = []
    if r > 0:
        neigbhor = [[currState[i][j] for j in range(
            len(currState[i]))] for i in range(len(currState))]
        neigbhor[r-1][c], neigbhor[r][c] = neigbhor[r][c], neigbhor[r-1][c]
        neighbors.append(neigbhor)
    if r < 2:
        neigbhor = [[currState[i][j] for j in range(
            len(currState[i]))] for i in range(len(currState))]
        neigbhor[r+1][c], neigbhor[r][c] = neigbhor[r][c], neigbhor[r+1][c]
        neighbors.append(neigbhor)
    if c > 0:
        neigbhor = [[currState[i][j] for j in range(
            len(currState[i]))] for i in range(len(currState))]
        neigbhor[r][c-1], neigbhor[r][c] = neigbhor[r][c], neigbhor[r][c-1]
        neighbors.append(neigbhor)
    if c < 2:
        neigbhor = [[currState[i][j] for j in range(
            len(currState[i]))] for i in range(len(currState))]
        neigbhor[r][c+1], neigbhor[r][c] = neigbhor[r][c], neigbhor[r][c+1]
        neighbors.append(neigbhor)
    return neighbors


def Astar_Tiles_misplaced(initialState, finalState):
    g = 0  # Inital Depth Zero
    h = misplacedTiles(initialState, finalState)
    OPENED = [(g+h, g, h, initialState, [initialState])]
    visited = list()

    while OPENED:
        # Get the node with the lowest f value (sum of g and h)
        (f, g, h, currState, path) = heapq.heappop(OPENED)

        if h == 0:
            path.append(finalState)
            return path

        if currState in visited:
            continue

        visited.append(currState)
        neighborStates = neighbors(currState)
        for neighborState in neighborStates:
            if neighborState not in visited:
                h = misplacedTiles(neighborState, finalState)
                heapq.heappush(
                    OPENED, (g + 1 + h, g + 1, h, neighborState, path + [neighborState]))

    return None


def Astar_Tiles_distance(initialState, finalState):
    g = 0  # Inital Depth Zero
    h = manhattan_distance(initialState, finalState)
    OPENED = [(g+h, g, h, initialState, [initialState])]
    visited = list()

    while OPENED:
        # Get the node with the lowest f value (sum of g and h)
        (f, g, h, currState, path) = heapq.heappop(OPENED)

        if h == 0:
            return path

        if currState in visited:
            continue

        visited.append(currState)
        neighborStates = neighbors(currState)
        for neighborState in neighborStates:
            if neighborState not in visited:
                h = manhattan_distance(neighborState, finalState)
                heapq.heappush(
                    OPENED, (g + 1 + h, g + 1, h, neighborState, path + [neighborState]))

    return None


initialState = []
print("Enter Initial State: ")
for _ in range(3):
    row = [x for x in input().split()]
    initialState.append(row)

finalState = []
print("Enter Final State: ")
for _ in range(3):
    row = [x for x in input().split()]
    finalState.append(row)

# h1(n) = Number of misplaced tiles
start_time = time.time()
path = Astar_Tiles_misplaced(initialState, finalState)
end_time = time.time()
elapsed_time = end_time - start_time

print(f"The Astar_Tiles_misplaced took {elapsed_time} seconds to run.")

if path != None:
    print(f"Number of Moves required to reach final state: {len(path) - 1}")
    print("Path: ")
    for state in path:
        printTiles(state)
        print()


# h2(n) = Sum of the tile distances from goal
start_time = time.time()
path = Astar_Tiles_distance(initialState, finalState)
end_time = time.time()
elapsed_time = end_time - start_time

print(f"The Astar_Tiles_distance took {elapsed_time} seconds to run.")

if path != None:
    print(f"Number of Moves required to reach final state: {len(path) - 1}")
    print("Path: ")
    for state in path:
        printTiles(state)
        print()
