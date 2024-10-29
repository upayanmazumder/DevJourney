#Program to find out whether a number is odd or even
n=int(input("Enter a number : "))
n=n**2
n=n**(1/2)
print(n) # n is now positive or zero
i=0
while(i<n) : 
    j=i
    i=i+1
print("i={0}\nj={1}".format(i, j))