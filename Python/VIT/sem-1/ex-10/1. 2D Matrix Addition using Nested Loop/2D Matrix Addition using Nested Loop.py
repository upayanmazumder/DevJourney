m1=[]
m2=[]
mSum=[]

# Populate the matrices
for i in range(2): # For each matrix
    m=[] # Initialise the matrix
    print(f"Matrix {i+1} >> ")
    for j in range(2): # For each row
        mRow=[] # Initialise the row
        print(f"\tRow {j+1} >> ")
        for k in range(2): # For each element in the row
            x=int(input(f"\t\tEnter element {k+1} : ")) # Enter row elements
            mRow.append(x) # Append elements to the row
        m.append(mRow) # Append row to the matrix

    # Assign the values to the appropriate matrix
    if i==0:
        m1=m 
    else:
        m2=m

# Calculate the sum matrix
for i in range(2): # For each row
    mSumR=[] # Initialise the row
    for j in range(2): # For each element in the row
        sum=m1[i][j]+m2[i][j]
        mSumR.append(sum)
    mSum.append(mSumR)

# Display the matrix sum
for i in range(2):
    for j in range(2):
        print(mSum[i][j], end=' ')
    print('\0')
