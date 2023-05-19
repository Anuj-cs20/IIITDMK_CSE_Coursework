import random
import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def print_world(grid):
    for row in grid:
        for cell in row:
            if cell['wumpus']:
                print('W', end='')

            if cell['pit']:
                print('P', end='')

            if cell['gold']:
                print('G', end='')

            if cell['breeze']:
                print('B', end='')

            if cell['stench']:
                print('S', end='')

            if cell['visited']:
                print('V', end='')

            print('\t', end='')
        print()


def get_neighbors(node, rows, cols):
    r, c = node
    neighbors = []
    if r > 0:
        neighbors.append((r-1, c))
    if r < rows-1:
        neighbors.append((r+1, c))
    if c > 0:
        neighbors.append((r, c-1))
    if c < cols-1:
        neighbors.append((r, c+1))
    return neighbors


def dfs(grid, node):
    grid[node[0]][node[1]]['visited'] = True
    print()
    print_world(grid)

    if grid[node[0]][node[1]]['gold']:
        return True
    neighbors = get_neighbors(node, len(grid), len(grid[0]))
    random.shuffle(neighbors)
    for neighbor in neighbors:
        if not grid[neighbor[0]][neighbor[1]]['visited']:
            if grid[neighbor[0]][neighbor[1]]['pit'] or grid[neighbor[0]][neighbor[1]]['wumpus']:
                continue

            if dfs(grid, neighbor):
                return True
    return False


def game(node, grid):
    grid[node[0]][node[1]]['visited'] = True
    while True:
        if dfs(grid, node):
            print()
            print("Found gold!")
            print_world(grid)
            return
        neighbors = get_neighbors(node, len(grid), len(grid[0]))
        unvisited_neighbors = [
            n for n in neighbors if not grid[n[0]][n[1]]['visited']]
        if not unvisited_neighbors:
            print("No unvisited neighbors!")
            return
        node = random.choice(unvisited_neighbors)


rows, cols = map(int, input("Enter Grid Size: ").split())
grid = [[{'pit': False, 'wumpus': False, 'gold': False, 'breeze': False, 'stench': False, 'visited': False}
         for _ in range(cols)] for _ in range(rows)]

num_pits = int(input("Enter num of pits: "))
for _ in range(num_pits):
    r, c = map(int, input().split())
    grid[r][c]['pit'] = True
    neighbors = get_neighbors((r, c), rows, cols)
    for neighbor in neighbors:
        grid[neighbor[0]][neighbor[1]]['breeze'] = True

num_wum = int(input("Enter num of wumpus: "))
for _ in range(num_wum):
    r, c = map(int, input().split())
    grid[r][c]['wumpus'] = True
    neighbors = get_neighbors((r, c), rows, cols)
    for neighbor in neighbors:
        grid[neighbor[0]][neighbor[1]]['stench'] = True


num_gold = int(input("Enter num of gold: "))
for _ in range(num_gold):
    r, c = map(int, input().split())
    grid[r][c]['gold'] = True

print()
print_world(grid)

game((0, 0), grid)
