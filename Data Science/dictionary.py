Dict = {}

while(1):
    print()
    print("Menu: ")
    print("a. Insert")
    print("b. Delete")
    print("c. Search")
    print("d. Exit")

    char = input("Enter an option: ")
    if char == 'a':
        rollNo = input("Enter Roll No: ")
        name = input("Enter name: ")
        cgpa = input("Enter CGPA: ")
        mobile = input("Enter mobile number: ")
        list = [name, cgpa, mobile]
        Dict[rollNo] = list
        print(Dict)
    elif char == 'b':
        rollNo = input("Enter Roll No: ")
        if rollNo in Dict:
            Dict.pop(rollNo)
            print("Successfully Deleted")
        else:
            print("Roll No doesn't exist")
        print(Dict)
    elif char == 'c':
        rollNo = input("Enter Roll No: ")
        if rollNo in Dict:
            print("Roll No. exists")
            print(Dict[rollNo])
        else:
            print("Roll No. doesn't exist")
    elif char == 'd':
        print("Exited")
        break
    else:
        print("Enter Correct input")
