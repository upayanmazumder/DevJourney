A1=[1,1,1,2,2,1,4,5,3,8,8,9,10,1]
LUn=[]  # List of Unique Elements

for i in range(len(A1)):
    if A1[i] not in LUn:
        LUn.append(A1[i])

print('List of unique elements:      ',LUn)

LUnF=[] # Frequency of elements of unique list
for i in range(len(LUn)): # For each element in unique list
    LUnF.append(0)  # Initialise the frequency to 0
    for j in range(len(A1)): # Check the unique element against all the elements of the original list
        if LUn[i]==A1[j]:
            LUnF[i]+=1
                       
print('Frequency of unique elements: ',LUnF)
    
    
maxF=LUnF[0]
minF=LUnF[0]

for i in range(len(LUnF)):
    if maxF<LUnF[i]:
        maxF=LUnF[i]
    if minF>LUnF[i]:
        minF=LUnF[i]

minFI=[]
maxFI=[]

for i in range(len(LUnF)):
    if maxF==LUnF:
        maxFI.append(LUn[i])
    if minF==LUnF:
        minFI.append(LUn[i])

print(maxFI, minFI)
