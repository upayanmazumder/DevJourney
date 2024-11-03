x = int(input("Enter a number: "))
n=x
s=0

# Sum of digits
while n:
    l=n%10
    n=n//10
    s+=l**3
    
if s==x:
    print(f"{x} is an armstrong number")
else:
    print(f"{x} is not an armstrong number")
