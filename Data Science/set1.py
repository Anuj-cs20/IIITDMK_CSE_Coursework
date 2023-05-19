Dict = {}

print("Menu: ")
print("a. Create Empty Set")
print("b. Insert")
print("c. Delete")
print("d. Search")
print("e. Print")
print("f. Union")
print("g. Intersection")
print("h. Set Difference")
print("i. Symmetric Difference")
print("j. Exit")

while(1):
    print()

    char = input("Enter an option: ")
    if char == "a":
        name = input("Enter set name: ")
        if name in Dict:
            print("already exists")
        else:    
            Dict[name] = set()
            print("Successfully created empty set")
    elif char == "b":
        name = input("Enter set name: ")
        if name in Dict:
            n = int(input("Enter size of set: "))
            for i in range(0, n):
                data = input("Enter data: ")
                Dict[name].add(data)
    elif char == "c":
        name = input("Enter set name: ")
        if name in Dict:
            data = input("Enter data: ")
            if data in Dict[name]:
                Dict[name].remove(data)
                print(Dict[name])
    elif char == "d":
        name = input("Enter set name: ")
        if name in Dict:
            data = input("Enter data: ")
            if data in Dict[name]:
                print("Found")
    elif char == "e":
        name = input("Enter set name: ")
        if name in Dict:
            print(Dict[name])
    elif char == "f":
        name1 = input("Enter set1 name: ")
        if name1 in Dict:
            name2 = input("Enter set2 name: ")
            if name2 in Dict:
                print(Dict[name1].union(Dict[name2]))
    elif char == "g":
        name1 = input("Enter set1 name: ")
        if name1 in Dict:
            name2 = input("Enter set2 name: ")
            if name2 in Dict:
                print(Dict[name1].intersection(Dict[name2]))
    elif char == "h":
        name1 = input("Enter set1 name: ")
        if name1 in Dict:
            name2 = input("Enter set2 name: ")
            if name2 in Dict:
                print(f"set1 - set2: {Dict[name1].difference(Dict[name2])}")
                print(f"set2 - set1: {Dict[name2].difference(Dict[name1])}")
    elif char == "i":
        name1 = input("Enter set1 name: ")
        if name1 in Dict:
            name2 = input("Enter set2 name: ")
            if name2 in Dict:
                print(Dict[name1].symmetric_difference(Dict[name2]))
    elif char == "j":
        break
    else:
        print("Enter correct input")
