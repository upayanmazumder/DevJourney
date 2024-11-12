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
""")

choice = input("Enter your choice: ")

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
    else:
        res = "Invalid choice"
    return res

if choice in 'abcdefg':
    if choice in 'deg' and b == 0:
        print("Division by zero is not allowed")
    else:
        res = evaluate(a,b,choice)
        print(f"Result: {res}")
else:
    print("Invalid choice")