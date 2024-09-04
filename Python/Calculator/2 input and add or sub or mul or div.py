x=float(input("Enter 1st number: "))
y=float(input("Enter 2nd number: "))
op=int(input("Please select the number corresponding to the operation you wish to perform \n1. Add\n2. Subtract\n3. Multiplication\n4. Division\n"))
if op>=1 and op<=4:
    if op==1:
        res=x+y
    elif op==2:
        res=x-y
    elif op==3:
        res=x*y
    elif op==4:
        res=x/y
    print("Result: ",res)
else:
    print("Invalid input!")
