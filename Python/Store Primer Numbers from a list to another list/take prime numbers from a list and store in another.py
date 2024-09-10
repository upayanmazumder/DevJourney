n=10
L1,L2=[],[]
for i in range(n):
    x=int(input(f'Enter number {i+1}: '))
    while x<=0:
        print("Please enter a positive number!")
        x=int(input(f'Enter number {i+1}: '))
    L1.append(x)

# Filter and store the prime numbers              
for i in range(n):
    prime=True
    for j in range(2,i):
        if L1[i]%j==0:
              prime=False
    if prime and L1[i] not in L2:
        L2.append(L1[i])
print(L2)
    
        
