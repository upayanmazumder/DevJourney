A1=[1,1,1,2,2,1,4,5,3,3,8,8,9,10,1]
L1,L2=[],[]

# Populate List 1
for i in range(len(A1)):
    if A1[i] not in L1:
        L1.append(A1[i])

# Populate List 2
i=-1
while len(A1)>len(L2):
    i+=1
    L2.append(0)
    for j in range(len(A1)):
        if A1[j]==i:
            L2[i]+=1 # Index number is the observed number, and its data the frequency

# Print List 1
print('The unique elements are:')
for i in range(len(L1)):
    print(f'{L1[i]}',end='')
    if i<len(L1)-1:
        print(',',end='')


# Print List 2
print('\n\nThe numbers and their respective frequencies are:')
print('   Number : Frequency')
for i in range(len(L2)):
    if L2[i]!=0:
        print(f'\t{i} : {L2[i]}') # Print the number followed by its frequency
