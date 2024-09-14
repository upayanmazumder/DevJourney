A1 = [1, 1, 1, 2, 2, 1, 4, 5, 3, 8, 8, 9, 10, 1]
L1, L2 = [], []

# Populate List 1 (Unique elements)
for i in range(len(A1)):
    if A1[i] not in L1:
        L1.append(A1[i])

# Populate List 2 (Frequency of each element)
i = -1
while len(A1) > len(L2):
    i += 1
    L2.append(0)
    for j in range(len(A1)):
        if A1[j] == i:
            L2[i] += 1  # Index number is the observed number, and its data the frequency

# Find the maximum frequency
fMax = max(L2)
fMaxItems = [i for i in range(len(L2)) if L2[i] == fMax]

# Find the minimum frequency (excluding zero frequencies)
fNonzero = [freq for freq in L2 if freq > 0]
fMin = min(fNonzero)
fMinItems = [i for i in range(len(L2)) if L2[i] == fMin]

# Print Maximum
print(f'\nThe numbers repeated the maximum number of times are: ', end = '')
for i in range(len(fMaxItems)):
    print(fMaxItems[i],end='')
    if i<len(fMaxItems)-1:
        print(',', end=' ')
print(f' repeated {fMax} time(s).')

print(f'The numbers repeated the least number of times are: ', end = '')
for i in range(len(fMinItems)):
    print(fMinItems[i],end='')
    if i<len(fMinItems)-1:
        print(',', end=' ')
print(f' repeated {fMin} time(s).')
