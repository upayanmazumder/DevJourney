x=int(input("Enter number: "))
n=[]

# Create a list with numbers in reverse order
while x:
    r=x%10
    n.append(r)
    x=x//10
# List with elements in correct order
n=n[::-1]
a=10**(len(n)-1)
print(a)
inc=a/10

### TODO