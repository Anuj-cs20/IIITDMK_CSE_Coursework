class AlignmentState:
    def __init__(self, i, j, path, totalCost):
        self.i = i
        self.j = j
        self.total_cost = totalCost
        self.path = path
        self.cost = len(path)

    def __lt__(self, others):
        return self.total_cost < others.total_cost


class SequenceAlignment:
    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2

    def alignment(self):
        # Initialize the starting curr_state
        start = AlignmentState(0, 0, [], self.heuristic(0, 0))
        openList = [start]
        closedList = set()

        while openList:
            # Get the curr_state with the lowest total cost
            curr_state = min(openList, key=lambda x: x.total_cost)
            openList.remove(curr_state)

            # If the curr_state represents the end of the sequences, return the path
            if curr_state.i == len(self.seq1) and curr_state.j == len(self.seq2):
                return curr_state.path

            # If the curr_state has not been closedList
            if (curr_state.i, curr_state.j) not in closedList:
                closedList.add((curr_state.i, curr_state.j))
                successor = []

                # Generate the child that represents an insertion in seq1
                if curr_state.i < len(self.seq1):
                    cost = curr_state.cost + 1
                    h = self.heuristic(curr_state.i + 1, curr_state.j)
                    child = AlignmentState(curr_state.i + 1, curr_state.j, curr_state.path +
                                           [('Insertion', self.seq1[curr_state.i])], cost + h)
                    successor.append(child)

                # Generate the child that represents a deletion in seq1
                if curr_state.j < len(self.seq2):
                    cost = curr_state.cost + 1
                    h = self.heuristic(curr_state.i, curr_state.j + 1)
                    child = AlignmentState(curr_state.i, curr_state.j + 1, curr_state.path +
                                           [('Deletion', self.seq2[curr_state.j])], cost + h)
                    successor.append(child)

                # Generate the child that represents a substitution
                if curr_state.i < len(self.seq1) and curr_state.j < len(self.seq2):
                    cost = curr_state.cost + \
                        (self.seq1[curr_state.i] != self.seq2[curr_state.j])
                    h = self.heuristic(curr_state.i + 1, curr_state.j + 1)
                    child = AlignmentState(curr_state.i + 1, curr_state.j + 1, curr_state.path +
                                           [('Substitution', self.seq1[curr_state.i], self.seq2[curr_state.j])], cost + h)
                    successor.append(child)

                # Add the successor to the openList
                openList.extend(successor)

        # If no path was found, return None
        return None

    def heuristic(self, i, j):
        return sum(self.seq1[k] != self.seq2[l] for k in range(i, len(self.seq1)) for l in range(j, len(self.seq2)))


seq1 = "AGTCA"
seq2 = "GGGGG"
alignedOps = SequenceAlignment(seq1, seq2)
ops = alignedOps.alignment()
print("Operations to be performed: ", ops)
min_cost = 0
for i in range(len(ops)):
    for j in range(1):
        if (ops[i][0] == 'Substitution'):
            if ops[i][1] == ops[i][2]:
                min_cost = min_cost
            else:
                min_cost += 1
        else:
            min_cost += 1

print("Optimal Cost: ", min_cost)
