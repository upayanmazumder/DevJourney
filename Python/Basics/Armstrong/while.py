x=int(input("Enter a number: "))
xOrg=x
xS=0
while x:
    l=x%10
    xS+=l**3
    x=x//10
print("Armstrong number") if xS==xOrg else print("Not an armstrong number")
    
