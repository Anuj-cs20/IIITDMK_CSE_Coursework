import pickle

print("\n======= MENU ======")
print("1. Write")
print("2. Read")
print("3. Search")
print("4. Exit")
while(1):
    opt = int(input("\nEnter option: "))
    if opt == 1:
        n = int(input("\nEnter number of books: "))
        print("Enter Book details")
        file = open('lib.dat', 'ab')
        for i in range(n):
            data = []
            print(f"Book: {i+1}")
            issn = input("ISSN: ")
            data.append(issn)
            title = input("Title: ")
            data.append(title)
            price = input("Price: ")
            data.append(price)
            edition = input("Edition: ")
            data.append(edition)
            year = input("Year: ")
            data.append(year)
            author = input("Author Name: ")
            data.append(author)

            pickle.dump(data, file)
        file.close()
    elif opt == 2:
        file = open('lib.dat', 'rb')
        while(1):
            i = 0
            try:
                data = pickle.load(file)
                print(f"\nBook: {i+1}")
                print(f"ISSN: {data[0]}")
                print(f"Title: {data[1]}")
                print(f"Price: {data[2]}")
                print(f"Edition: {data[3]}")
                print(f"Year: {data[4]}")
                print(f"Author Name: {data[5]}")
                i = i + 1
            except EOFError:
                print('\nEnd of the file')
                break
        file.close()
    elif opt == 3:
        title = input("Book title: ")
        file = open('lib.dat', 'rb')
        while(1):
            try:
                data = pickle.load(file)
                if title == data[1]:
                    print(f"ISSN: {data[0]}")
                    print(f"Title: {data[1]}")
                    print(f"Price: {data[2]}")
                    print(f"Edition: {data[3]}")
                    print(f"Year: {data[4]}")
                    print(f"Author Name: {data[5]}")
                    break
            except EOFError:
                print(f'Book {title} is not found')
                break
        file.close()
    elif opt == 4:
        print("Exit...")
        break
    else:
        print("Enter proper option")
