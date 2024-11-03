n=10
A1,A2=[],[]

# Get user input
for i in range(n):
    x=int(input(f'Enter number {i+1}: '))
    while x<=0:
        print("Please enter a positive number!")
        x=int(input(f'Enter number {i+1}: '))
    A1.append(x)

# Filter and store the prime numbers              
for i in range(n): # For each number the user entered
    prime=True # Initially assume its prime
    for j in range(2,A1[i]): # Start a iterative check to find whether at least one number can divide it
        if A1[i]%j==0:
            prime=False
    if prime and A1[i] not in A2: # If no factors were found and the number isnt already stored in new list
        A2.append(A1[i]) 

if len(A2)>0:
    print(f'Original List: {A1}\nNew List (PRIME): {A2}')
else:
    print('No prime numbers')