n=10
L1,L2=[],[]

# Get user input
for i in range(n):
    x=int(input(f'Enter number {i+1}: '))
    while x<=0:
        print("Please enter a positive number!")
        x=int(input(f'Enter number {i+1}: '))
    L1.append(x)

# Filter and store the prime numbers              
for i in range(n): # For each number the user entered
    prime=True # Initially assume its prime
    for j in range(2,L1[i]): # Start a iterative check to find whether at least one number can divide it
        if L1[i]%j==0:
            prime=False
    if prime and L1[i] not in L2: # If no factors were found and the number isnt already stored in new list
        L2.append(L1[i]) 

if len(L2)>0:
    print(f'Original List: {L1}\nNew List (PRIME): {L2}')
else:
    print('No prime numbers')