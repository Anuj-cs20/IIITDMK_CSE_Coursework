while(1):
    print()
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

    char = input("Enter an option: ")
    if char == "a":
        s = set()
        s1 = set()
        print("Successfully created empty set")
    elif char == "b":
        n = int(input("Enter size of set: "))
        for i in range(0, n):
            data = input("Enter data: ")
            s.add(data)
        n1 = int(input("Enter size of set1: "))
        for i in range(0, n1):
            data = input("Enter data: ")
            s1.add(data)
    elif char == "c":
        key = input("Enter data to be deleted: ")
        if key in s:
            s.remove(key)
            print("Successfully deleted")
        else:
            print("key not found")
    elif char == "d":
        key = input("Enter data: ")
        if key in s:
            print("key found")
        else:
            print("key not found")
    elif char == "e":
        print(s)
        print(s1)
    elif char == "f":
        print(s)
        print(s1)
        print(s.union(s1))
    elif char == "g":
        print(s)
        print(s1)
        print(s.intersection(s1))
    elif char == "h":
        print(s)
        print(s1)
        print(f"set - set1: {s.difference(s1)}")
        print(f"set1 - set: {s1.difference(s)}")
    elif char == "i":
        print(s)
        print(s1)
        print(s.symmetric_difference(s1))
    elif char == "j":
        break
    else:
        print("Enter correct input")