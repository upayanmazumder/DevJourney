x=float(input("Enter the first number: "))
y=float(input("Enter the second number: "))
sum=x+y
diff=x-y
prod=x*y
exp=x**y
print("Sum={0}\nDifference={1}\nProduct={2}\nExponent={3}".format(sum,diff,prod,exp))
if(y!=0):
    quot=x/y
    mod=x%y
    fdiv=x//y
    print("Quotient={0}\nModulus={1}\nFloor Division={2}".format(quot,mod,fdiv))
else:
    print("Cannot find quotient, modulus and floor divison as the 2nd number is zero")
