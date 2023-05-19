class Node():
    def __init__(self, x):
        self.data = x
        self.NextNode = None


class queue():
    def __init__(self):
        self.HNode = self.TNode = None

    def peek(self):
        if self.HNode is None:
            print("Queue is Empty")
        else:
            print(self.HNode.data)

    def enQueue(self, x):
        if self.HNode is None:
            self.TNode = self.HNode = Node(x)
        else:
            NewNode = Node(x)
            self.TNode.NextNode = NewNode
            self.TNode = NewNode

    def deQueue(self):
        if self.HNode is None:
            print("Queue is Empty (Underflow)")
        elif self.HNode is self.TNode:
            hnode = self.HNode
            self.TNode = self.HNode = None
            print(f"DeQueueed Element: {hnode.data}")
            del hnode
        else:
            hnode = self.HNode
            self.HNode = self.HNode.NextNode
            print(f"DeQueueed Element: {hnode.data}")
            del hnode

    def printQueue(self):
        if self.HNode is None:
            print("Queue is Empty")
        else:
            print("Queue: ")
            tmpNode = self.HNode
            while tmpNode is not None:
                print(tmpNode.data)
                tmpNode = tmpNode.NextNode

    def delQueue(self):
        while self.HNode is not None:
            dnode = self.HNode
            self.HNode = self.HNode.NextNode
            del dnode
        self.HNode = self.TNode = None


queue1 = queue()

while 1:
    print("")
    print("1. EnQueue")
    print("2. DeQueue")
    print("3. Print Queue")
    print("4. Peek")
    print("4. Exit")

    opt = int(input("Enter option: "))
    if opt is 1:
        queue1.enQueue(input("Enter element to be EnQueueed: "))
    elif opt is 2:
        queue1.deQueue()
    elif opt is 3:
        queue1.printQueue()
    elif opt is 4:
        queue1.peek()
    elif opt is 5:
        queue1.delQueue()
        print("Exited")
        break
    else:
        print("Enter proper option")
