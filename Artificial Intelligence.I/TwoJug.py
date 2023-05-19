def bfs(J, FJ):
    queue = [(0, 0)]
    visited = []

    while queue:
        tup = queue.pop(0)
        visited.append(tup)

        if tup == FJ:
            print("Yes")
            return
        else:
            # fill j1
            if (J[0], tup[1]) not in visited:
                queue.append((J[0], tup[1]))

            # fill j2
            if (tup[0], J[1]) not in visited:
                queue.append((tup[0], J[1]))

            # empty j1
            if (0, tup[1]) not in visited:
                queue.append((0, tup[1]))

            # empty j2
            if (tup[0], 0) not in visited:
                queue.append((tup[0], 0))

            # pour j1 -> j2
            if tup[1] < J[1] and tup[0] > 0:
                if tup[0] <= J[1] - tup[1]:
                    if (0, tup[0] + tup[1]) not in visited:
                        queue.append((0, tup[0] + tup[1]))
                else:
                    if (tup[0] + tup[1] - J[1], J[1]) not in visited:
                        queue.append((tup[0] + tup[1] - J[1], J[1]))

            # pour j2 -> j1
            if tup[0] < J[0] and tup[1] > 0:
                if tup[1] <= J[0] - tup[0]:
                    if (tup[0] + tup[1], 0) not in visited:
                        queue.append((tup[0] + tup[1], 0))
                else:
                    if (J[0], tup[0] + tup[1] - J[0]) not in visited:
                        queue.append((J[0], tup[0] + tup[1] - J[0]))

    print("No")


bfs((3, 5), (1, 0))
