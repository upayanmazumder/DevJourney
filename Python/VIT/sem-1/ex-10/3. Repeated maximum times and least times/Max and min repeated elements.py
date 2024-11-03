A1=[1,1,1,2,2,1,4,5,3,3,8,8,9,10,1]
L=[]

# Populate List 2
i=-1
while len(A1)>len(L):
    i+=1
    L.append(0)
    for j in range(len(A1)):
        if A1[j]==i:
            L[i]+=1 # Index number is the observed number, and its data the frequency

# Find the maximum and minimum frequencies
fMax=L[0]
fMin=100
for i in range(len(L)):
    if L[i] > fMax:
        fMax = L[i]
    if L[i] < fMin and L[i]!=0:
        fMin = L[i]

# Find the numbers with the maximum and minimum numbers
fMaxItems = []
fMinItems = []

for i in range(len(L)):
    if L[i] == fMax:
        fMaxItems.append(i)
    if L[i] == fMin:
        fMinItems.append(i)

# Print
print(f'Max: {fMaxItems} repeated {fMax} time(s).')
print(f'Min: {fMinItems} repeated {fMin} time(s).')