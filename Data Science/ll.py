'''
To implement linked list using references

x=[1,2,3] # x is the refenrece for [1,2,3]
print(x)
y=x # y is the reference of x
print(y)
y.append(89)
print(y)
print(x)
'''
# Implementation of List ADT


class Node():
  def __init__(self, x):
      self.data = x
      self.NextNode = None


class LinkedList():
  def __init__(self):
      self.Hnode = None

  def Insert(self, x, i):
      NewNode = Node(x)
      if(i is 1):
        NewNode.NextNode = self.Hnode  # link1
        self.Hnode = NewNode  # link2

      else:
        pos = 1
        tnode = self.Hnode
        while((tnode is not None) and (pos < i-1)):
            pos = pos+1
            tnode = tnode.NextNode
        temp = tnode.NextNode  # temp is the ref of ith node
        # the Next Node in (i-1)th node becomes reference of newly crated node
        tnode.NextNode = NewNode
        NewNode.NextNode = temp  # temp is  ith node before inserstion

  def Delete(self, n):
    tnode = self.Hnode
    if(n == 1):
      dnode = self.Hnode
      self.Hnode = self.Hnode.NextNode
    else:
      i = 1
      while((tnode is not None) and (i < n-1)):
        i = i+1
        tnode = tnode.NextNode

      #tnode is refering to n-1th node
      dnode = tnode.NextNode  # dnode is refering to nth node
      tnode.NextNode = dnode.NextNode
    del dnode  # OS will include space allotted for dnode into free memory

  def Search(self, x):
        tnode = self.Hnode
        while((tnode is not None) and (tnode.data is not x)):
            tnode = tnode.NextNode
            if(tnode is not None):
                print("yes")
            else:
                print("No")

  def PrintList(self):
    print(self.Hnode)
    tnode = self.Hnode
    while(tnode is not None):
        print(tnode.data)
        tnode = tnode.NextNode


List1 = LinkedList()  # List1 represents empty list
'''
n1=Node(89)
List1.Hnode=n1 #
#print(List1.Hnode.data)
n2=Node(11)
n1.NextNode=n2
n3=Node(17)
n2.NextNode=n3
'''

List1.Insert(21, 1)
List1.Insert(13, 1)
List1.Insert(27, 3)
List1.Insert(17, 2)
List1.PrintList()
List1.Delete(2)
List1.PrintList()
#List1.Search(270)
