# split() will return substrings
# list = input('Enter the list of numbers: ').split()
# list = [int(x) for x in list]

len = int(input("Enter the length of the list: "))
list = []
for i in range(0, len):
    list.append(int(input("Enter list element: ")))

for i in range(1, len):
    key = list[i]
    j = i - 1
    while j >= 0 and key < list[j]:
        list[j + 1] = list[j]
        j = j - 1
    list[j + 1] = key
print('Sorted list:', list)