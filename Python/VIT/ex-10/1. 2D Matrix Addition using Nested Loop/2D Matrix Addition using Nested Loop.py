m1=[]
m2=[]
mSum=[]

for i in range(2): # For each matrix
    print(f"Matrix {i+1}>>>") # Display the matrix number
    mC=[] # Initialise the columns
    for j in range(2):  # For each column
        print(f"\tColumn {j+1}>>>") # Display the column number
        mR=[] # initialise the row 
        for k in range(2):  # For each row 
            x=int(input(f"\t\tEnter element {k+1}:")) # Take input
            mR.append(x) # Append element to row
        y=mR 
        mC.append(y) # Append row to column
    z=mC
    # Populate the matrices
    if i==0:
        m1=z
    elif i==1:
        m2=z

# Calculate the matrix sum
for i in range(2): # For each column
    mSumR=[]
    for j in range(2): # For each row
        mSumR.append(m1[i][j]+m2[i][j])
    mSum.append(mSumR)

print(m1,'+',m2,'=',mSum)



# Update it to use properly defined variables. mR and mC is incorrect naming for its functions. 
# Take input row-wise instead of columnwise