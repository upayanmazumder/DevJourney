l = []
for i in range(2): # For each set
    N = int(input(f"How many elements in set {i+1}: "))
    li = []
    for j in range(N):  # For each set element
        x=eval(input(f"Set {i+1} >> Element {j+1}: "))
        li.append(x)
    l.append(set(li))

s1 = set(l[0])
s2 = set(l[1])

if s1.issuperset(s2):
    print("Set 1 is superset of Set 2")
else:
    print("Set 1 is not superset of Set 2")
