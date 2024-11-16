import calculator as c

a = float(input("Enter a: "))
b = float(input("Enter b: "))

print("""
    a. Add
    b. Subtract
    c. Multiply
    d. Divide
    e. Floor Divide
    f. Power
    g. Modulus
    h. Square Root
    i. Absolute
    j. Factorial
    k. GCD
    l. LCM
    0. End Program
""")

def evaluate(a, b, choice):
    if choice == 'a':
        res = c.add(a, b)
    elif choice == 'b':
        res = c.subtract(a, b)
    elif choice == 'c':
        res = c.multiply(a, b)
    elif choice == 'd':
        res = c.divide(a, b)
    elif choice == 'e':
        res = c.floor_divide(a, b)
    elif choice == 'f':
        res = c.power(a, b)
    elif choice == 'g':
        res = c.modulus(a, b)
    elif choice == 'h':
        res = f"Square root of {a} is {c.square_root(a)} and that of {b} is {c.square_root(b)}"
    elif choice == 'i':
        res = f"Absolute of {a} is {c.absolute(a)} and that of {b} is {c.absolute(b)}"
    elif choice == 'j':
        res = f"Factorial of {a} is {c.factorial(a)} and that of {b} is {c.factorial(b)}"
    elif choice == 'k':
        res = c.gcd(a, b)
    elif choice == 'l':
        res = c.lcm(a,b)
    else:
        res = "Invalid choice"
    return res

def display_result(choice):
    if choice in 'abcdefghijkl':
        if choice in 'deg' and b == 0:
            print("Division by zero is not allowed")
        else:
            res = evaluate(a,b,choice)
            print(f"Result: {res}")

    elif choice == '0':
        print("Ending program")
    else:
        print("Invalid choice")

choice = input("Enter your choice: ")
display_result(choice)

while choice != '0':
    choice = input("Enter your choice: ")
    display_result(choice)