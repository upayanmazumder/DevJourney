n=10
m=[]
for i in range(n):
    m.append(int(input(f"Enter {i+1}th number: ")))
for j in range(n-1):    # In each traverse
    for k in range(n-1):    # For each element
        if m[k]>m[k+1]:     # left element > right element?
            # Swap
            temp=m[k]
            m[k]=m[k+1]
            m[k+1]=temp

for i in range(n):
    print(m[i], end='')
    if i<n-1:
        print(',', end='')
    

