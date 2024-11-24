import calculator as c

x = float(input("Enter number 1: "))
y = float(input("ENter number 2: "))

print("""
    1. Addition
    2. Subtraction
    3. Multiplication
    4. Division
    5. Modulo Operation
    6. Exit
""")


def getChoice(x,y):
    choice = int(input("Enter choice: "))
    if choice >= 1 and choice <= 6:
        if choice == 1:
            res = c.add(x,y)
        elif choice == 2:
            res = c.subtract(x,y)
        elif choice == 3:
            res = c.product(x,y)
        elif choice == 4:
            res = c.divide(x,y)
        elif choice == 5:
            res = c.modulo(x,y)

        if choice >= 1 and choice <= 5:
            print(res)
            getChoice(x,y)
        else:
            print("Stopping program")    
    else:
        print("Invalid Choice!")
        getChoice(x,y)

getChoice(x,y)
