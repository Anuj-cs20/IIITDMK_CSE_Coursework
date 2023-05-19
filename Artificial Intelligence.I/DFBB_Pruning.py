import sys
import os
if not os.environ.get("ONLINE JUDGE"):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

ttt = [[-1, -1, -1], [-1, -1, -1], [-1, -1, -1]]
num = int(input("Enter number of changes: "))
print("Enter all changes: ")
for _ in range(num):
    i, j, v = [int(x) for x in input().split()]
    ttt[i][j] = v


def pri(ttt):
    for i in range(3):
        for j in range(3):
            if ttt[i][j] == 0:
                print(0, end=' ')
            elif ttt[i][j] == 1:
                print(1, end=' ')
            else:
                print(' ', end=' ')
        print()


print("\nCurrent State of the Game:")
pri(ttt)
depth = 9 - num
MAX, MIN = 1000, -1000


def check(ttt):
    if (ttt[0][0] == 1 and ttt[0][1] == 1 and ttt[0][2] == 1) or (ttt[1][0] == 1 and ttt[1][1] == 1 and ttt[1][2] == 1) or (ttt[2][0] == 1 and ttt[2][1] == 1 and ttt[2][2] == 1) or (ttt[0][0] == 1 and ttt[1][0] == 1 and ttt[2][0] == 1) or (ttt[0][1] == 1 and ttt[1][1] == 1 and ttt[2][1] == 1) or (ttt[0][2] == 1 and ttt[1][2] == 1 and ttt[2][2] == 1) or (ttt[0][2] == 1 and ttt[1][1] == 1 and ttt[2][0] == 1) or (ttt[0][0] == 1 and ttt[1][1] == 1 and ttt[2][2] == 1):
        return 1
    elif (ttt[0][0] == 0 and ttt[0][1] == 0 and ttt[0][2] == 0) or (ttt[1][0] == 0 and ttt[1][1] == 0 and ttt[1][2] == 0) or (ttt[2][0] == 0 and ttt[2][1] == 0 and ttt[2][2] == 0) or (ttt[0][0] == 0 and ttt[1][0] == 0 and ttt[2][0] == 0) or (ttt[0][1] == 0 and ttt[1][1] == 0 and ttt[2][1] == 0) or (ttt[0][2] == 0 and ttt[1][2] == 0 and ttt[2][2] == 0) or (ttt[0][2] == 0 and ttt[1][1] == 0 and ttt[2][0] == 0) or (ttt[0][0] == 0 and ttt[1][1] == 0 and ttt[2][2] == 0):
        return 1
    else:
        return 0


def alphabetaPruning(ttt, d, win, alpha, beta, chance):
    if d == depth:
        return check(ttt)

    if win:
        bestVal = MIN
        for i in range(3):
            for j in range(3):
                if ttt[i][j] == -1:
                    ttt[i][j] = chance
                    if check(ttt):
                        value = 1
                    else:
                        value = alphabetaPruning(
                            ttt, d + 1, 0, alpha, beta, chance)
                    # print()
                    # pri(ttt)
                    # print(value)
                    ttt[i][j] = -1
                    bestVal = max(bestVal, value)
                    alpha = max(alpha, bestVal)
                    if beta <= alpha:
                        break
            if beta <= alpha:
                break
        return bestVal
    else:
        bestVal = MAX
        for i in range(3):
            for j in range(3):
                if ttt[i][j] == -1:
                    ttt[i][j] = not chance
                    if check(ttt):
                        value = -1
                    else:
                        value = alphabetaPruning(
                            ttt, d + 1, 1, alpha, beta, chance)

                    # print()
                    # pri(ttt)
                    # print(value)
                    ttt[i][j] = -1
                    bestVal = min(bestVal, value)
                    beta = min(beta, bestVal)
                    if beta <= alpha:
                        break
            if beta <= alpha:
                break
        return bestVal


chance = int(input("How will play next(1 ot 0): "))
print(f"\nMaximizing {chance}'s chance of winning....")
v = alphabetaPruning(ttt, 0, True, MIN, MAX, chance)
print(f"He/She with {chance} will", end=' ')
if v == 1:
    print("win.")
elif v == -1:
    print("loss.")
else:
    print("tie.")
