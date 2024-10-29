def sum(x,y):
    sum=x+y
    return sum

def prod(x,y):
    prod=x*y
    return prod

def diff(x,y):
    diff=x-y
    return diff

def quot(x,y):
    quot=x/y
    return quot

def rem(x,y):
    rem=x%y
    return rem

a=int(input("Enter number 1 : "))
b=int(input("Enter number 2 : "))
s=sum(a,b)
p=prod(a,b)
d=diff(a,b)
q=quot(a,b)
r=rem(a,b)
print("User input => {0} & {1}".format(a,b))
print("Sum = {0}\nDifference = {1}\nProduct = {2}\nQuotient = {3}\nRemainder = {4}".format(s,d,p,q,r))
