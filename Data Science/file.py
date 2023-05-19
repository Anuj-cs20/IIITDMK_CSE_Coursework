import pickle

def WriteFile():
  file1 = open('Employee.dat', 'wb')
  while(1):
    x = []
    name = input('\n Enter EmpName \n')
    x.append(name)
    eid = input('\n Enter EmpId \n')
    x.append(eid)
    bpay = int(input('\n Enter Basic Bay \n'))  # input() outputs string
    x.append(bpay)
    print(x)
    pickle.dump(x, file1)
    opt = int(input('\n Enter 1 to continue \n 0  to stop \n'))
    if(opt == 0):
        break

  file1.close()


def ReadFile():
    file1 = open('Employee.dat', 'rb')
    while(1):
      try:
          x = pickle.load(file1)
          print(x)
      except EOFError:
          print('End of the file')
          break
    file1.close()


WriteFile()
ReadFile()
