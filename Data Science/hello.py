def el(v,l=[]):
    l.append(v)
    return l
l1 = el(10)
l2 = el(123,[])
l3 = el('a')
print(l1)
print(l2)
print(l3)
