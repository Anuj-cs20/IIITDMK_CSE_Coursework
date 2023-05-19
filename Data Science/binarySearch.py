# list = input('Enter the list of numbers: ').split()
# list = [int(x) for x in list]

len = int(input("Enter the length of the list: "))
list = []
for i in range(0, len):
    list.append(int(input("Enter list element: ")))

list.sort()

key = int(input('Enter the key of number: '))
low = 0
high = len-1
flag = 0

while low <= high:
    mid = low + (high - low) // 2
    if list[mid] == key:
        flag = 1
        break
    elif list[mid] > key:
        high = mid - 1
    elif list[mid] < key:
        low = mid + 1

if flag == 1:
    print("Key Found")
else:
    print("Key not Found")
