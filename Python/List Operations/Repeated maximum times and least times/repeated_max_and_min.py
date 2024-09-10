A1=[1,1,1,2,2,1,4,5,3,8,8,9,10,1]
lA1=len(A1)
L1=[],[]

# Populate List 1
i=-1
while len(A1)>len(L1):
    i+=1
    L1.append(0)
    for j in range(len(A1)):
        if A1[j]==i:
            L1[i]+=1 # Index number is the observed number, and its data the frequency


max=L1[0]
