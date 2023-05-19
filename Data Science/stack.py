class Node():
    def __init__(self, x):
        self.data = x
        self.NextNode = None


class stack():
    def __init__(self):
        self.HNode = None

    def peek(self):
        if self.HNode is None:
            print("Stack is Empty")
        else:
            print(self.HNode.data)

    def push(self, x):
        if self.HNode is None:
            self.HNode = Node(x)
        else:
            NewNode = Node(x)
            NewNode.NextNode = self.HNode
            self.HNode = NewNode   

    def pop(self):
        if self.HNode is None:
            print("Stack is Empty (Underflow)")
        else:
            pnode = self.HNode
            self.HNode = self.HNode.NextNode
            print(f"Poped Element: {pnode.data}")
            del pnode

    def printStack(self):
        if self.HNode is None:
            print("Stack is Empty")
        else:
            print("Stack: ")
            tmpNode = self.HNode
            while tmpNode is not None:
                print(tmpNode.data)
                tmpNode = tmpNode.NextNode  

    def delStack(self):
        while self.HNode is not None:
            dnode = self.HNode
            self.HNode = self.HNode.NextNode
            del dnode

stack1 = stack()

while 1:
    print("")
    print("1. Push")
    print("2. Pop")
    print("3. Peek")
    print("4. Print Stack")
    print("5. Exit")

    opt = int(input("Enter option: "))
    if opt is 1:
        stack1.push(input("Enter element to be pushed: "))
    elif opt is 2:
        stack1.pop()
    elif opt is 3:
        stack1.peek()
    elif opt is 4:
        stack1.printStack()
    elif opt is 5:
        stack1.delStack()
        print("Exited")
        break
    else:
        print("Enter proper option")    
