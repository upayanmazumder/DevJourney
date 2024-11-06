def make_list():
    """Populate the list"""
    l = []
    n = int(input("Enter length of list: "))
    for i in range(n):
        x = float(input(f"Enter element {i+1}: "))
        l.append(x)
    print(l)
    return l

def op(c,l):
    """Handles which operation to perform"""
    if c>0 and c<6:
        if c==1:
            res = op1(l)
        elif c==2:
            res = op2(l)
        elif c==3:
            res = op3(l)
        elif c==4:
            res = op4(l)
        elif c==5:
            res = op5(l)
        print(res)
    else:
        print("Invalid choice")

def op1(l):
    """Add all elements of given list"""
    sum = 0
    for i in range(len(l)):
        sum += l[i]
    return sum

def op2(l):
    """Add even index numbers"""
    sum = 0
    for i in range(len(l)):
        if i % 2 == 0:
            sum += l[i]
    return sum

def op3(l):
    """Add odd index numbers"""
    sum = 0
    for i in range(len(l)):
        if i % 2 != 0:
            sum += l[i]
    return sum

def op4(l):
    """Factorial of first element"""
    x = l[0]
    def factorial(y):
        if y == 1:
            return 1
        else:
            return y * factorial(y-1)
    fact = factorial(x)
    return fact

def op5(l):
    """Check if second element is armstrong number or not"""
    x = l[1]
    xOrg=x
    xS=0
    while x:
        l=x%10
        xS+=l**3
        x=x//10
    if xS==xOrg:
        res = True
    else: 
        res = False
    return res

def print_instructions():
    """Print the instructions"""
    print("""
        1. Add all the elements of the given list.
        2. Add all the elements present in the even index of the given list.
        3. Add all the elements present in the odd index of the given list.
        4. Display the factorial of the 1st element given in the list.
        5. Check if the second element of the list is an Armstrong number or not.
        6. End
    """)

l = make_list()
print_instructions()
choice = int(input("Enter the operation you wish to perform: "))
if choice != 6:
    op(choice,l)

while choice != 6:
    choice = int(input("Enter the operation you wish to perform: "))
    if choice != 6:
        op(choice,l)
print("Stopping..")