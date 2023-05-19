class Hanoi:
    def __init__(self, n):
        self.n = n
        self.S = []
        self.A = []
        self.D = []
        for i in range(n, 0, -1):
            self.S.append(i)

    def SA(self):
        disk1 = self.S[-1] if len(self.S) > 0 else self.n + 1
        disk2 = self.A[-1] if len(self.A) > 0 else self.n + 1
        if disk1 < disk2:
            disk = self.S.pop()
            self.A.append(disk)
            print(f"Move disk {disk} form S to A")
        else:
            disk = self.A.pop()
            self.S.append(disk)
            print(f"Move disk {disk} form A to S")

    def SD(self):
        disk1 = self.S[-1] if len(self.S) > 0 else self.n + 1
        disk2 = self.D[-1] if len(self.D) > 0 else self.n + 1
        if disk1 < disk2:
            disk = self.S.pop()
            self.D.append(disk)
            print(f"Move disk {disk} form S to D")
        else:
            disk = self.D.pop()
            self.S.append(disk)
            print(f"Move disk {disk} form D to S")

    def AD(self):
        disk1 = self.A[-1] if len(self.A) > 0 else self.n + 1
        disk2 = self.D[-1] if len(self.D) > 0 else self.n + 1
        if disk1 < disk2:
            disk = self.A.pop()
            self.D.append(disk)
            print(f"Move disk {disk} form A to D")
        else:
            disk = self.D.pop()
            self.A.append(disk)
            print(f"Move disk {disk} form D to A")

    def nonRecursive(self):
        if self.n % 2 == 0:
            for i in range(1, (1 << self.n)):
                if i % 3 == 1:
                    self.SA()
                elif i % 3 == 2:
                    self.SD()
                else:
                    self.AD()
        else:
            for i in range(1, (1 << self.n)):
                if i % 3 == 1:
                    self.SD()
                elif i % 3 == 2:
                    self.SA()
                else:
                    self.AD()

    def recursive(self, n, source, destination, aux):
        if n > 0:
            self.recursive(n-1, source, aux, destination)
            print("Move disk", n, "from", source, "to", destination)
            self.recursive(n-1, aux, destination, source)


# Number of disks
N = 3
print("\nTower of Hanoi")
hanoi = Hanoi(N)

print("\nIterative Way")
hanoi.nonRecursive()

print("\nRecursive Way")
hanoi.recursive(N, 'S', 'D', 'A')
