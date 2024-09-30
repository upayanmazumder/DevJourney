l = []
l1 = [10, 45, 34, 20, 11]
l2 = [11, 25, 45, 20]

# Convert to set
s1 = set(l1)
s2 = set(l2)

# Find intersection set
sI=s1.intersection(s2)

# Unique elements of set 1
for i in s1:
    if i not in sI:
        l.append(i)
# Unique elemenets of set 2
for i in s2:
    if i not in sI:
        l.append(i)

print(l)