# Get 4 sets from the user. Find the common element across all sets.

n = 4
l = []

# Populate the list
for i in range(n): # For each set
    N = int(input(f"How many elements in set {i+1}: "))
    li = []
    for j in range(N):  # For each set element
        x=eval(input(f"Set {i+1} >> Element {j+1}: "))
        li.append(x)
    l.append(set(li))

# Convert to sets
s1 = set(l[0])
s2 = set(l[1])
s3 = set(l[2])
s4 = set(l[3])

# Find intersection set
sI=s1.intersection(s2).intersection(s3).intersection(s4)

print(sI)