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
                print('W', end='\t')
            elif cell['pit']:
                print('P', end='\t')
            elif cell['gold']:
                print('G', end='\t')
            else:
                print('-', end='\t')
        print()


def print_agent(agent):
    for row in agent:
        for cell in row:
            if cell['breeze']:
                print('B', end=',')

            if cell['stench']:
                print('S', end=',')

            if cell['visited']:
                print('V', end='\t')
            else:
                print('-', end='\t')
        print()


def game(node, agent, grid):
    r, c = node
    agent[r][c]['visited'] = True

    # check if gold is found
    if grid[r][c]['gold']:
        print("Gold Found!")
        return True

    # check for breeze and stench
    breeze, stench = False, False
    for i, j in [(r+1, c), (r-1, c), (r, c+1), (r, c-1)]:
        if i >= 0 and i < len(grid) and j >= 0 and j < len(grid[0]):
            if grid[i][j]['pit']:
                breeze = True
            if grid[i][j]['wumpus']:
                stench = True
    agent[r][c]['breeze'] = breeze
    agent[r][c]['stench'] = stench


    print()
    print_agent(agent)
    # if wumpus is present and its location is known, kill it
    # if stench and not grid[r][c]['wumpus']:
    #     print("Wumpus killed!")
    #     return False

    # move to adjacent cell
    for i, j in [(r+1, c), (r-1, c), (r, c+1), (r, c-1)]:
        if i >= 0 and i < len(grid) and j >= 0 and j < len(grid[0]):
            if not agent[i][j]['visited'] and not grid[i][j]['pit']:
                if not stench or grid[i][j]['wumpus']:
                    return game((i, j), agent, grid)

    # backtrack if all adjacent cells are visited or contain pits or wumpus
    return False



rows, cols = map(int, input("Enter Grid Size: ").split())
grid = [[{'pit': False, 'wumpus': False, 'gold': False}
         for _ in range(cols)] for _ in range(rows)]

num_pits = int(input("Enter num of pits: "))
for _ in range(num_pits):
    r, c = map(int, input().split())
    grid[r][c]['pit'] = True

num_wum = int(input("Enter num of wumpus: "))
for _ in range(num_wum):
    r, c = map(int, input().split())
    grid[r][c]['wumpus'] = True

num_gold = int(input("Enter num of gold: "))
for _ in range(num_gold):
    r, c = map(int, input().split())
    grid[r][c]['gold'] = True

agent = [[{'breeze': False, 'stench': False, 'visited': False}
          for _ in range(cols)] for _ in range(rows)]

print()
print_world(grid)

game((0, 0), agent, grid)
