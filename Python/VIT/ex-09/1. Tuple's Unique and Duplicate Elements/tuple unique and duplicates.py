t = (1, 2, 2, 3, 4, 4, 4, 5, 6, 6)

eU = []  # Store unique elements
eD = []  # Store duplicate elements
eC = []  # Store count of each element

# Count the occurrences of each element in the tuple
for i in range(len(t)):
    count = 0
    for j in range(len(t)):
        if t[i] == t[j]:
            count += 1
    eC.append(count)

# Classify elements as unique or duplicate based on their counts
for i in range(len(t)):
    if eC[i] == 1:
        if t[i] not in eU:
            eU.append(t[i])
    else:
        if t[i] not in eD:
            eD.append(t[i])

if len(eU) == 0:
    print("No unique elements found.")
else:
    print("Unique elements:")
    for i in range(len(eU)):
        print(eU[i],end=' ')
        if i < len(eU)-1:
            print(',',end=' ')

if len(eD) == 0:
    print("\nNo duplicate elements found.")
else:
    print("\nDuplicate elements:")
    for i in range(len(eD)):
        print(eD[i],end=' ')
        if i < len(eD)-1:
            print(',',end=' ')
