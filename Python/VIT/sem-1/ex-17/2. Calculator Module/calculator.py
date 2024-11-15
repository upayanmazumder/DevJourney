def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    return a / b

def floor_divide(a, b):
    return a // b

def power(a, b):
    return a ** b

def modulus(a, b):
    return a % b

def square_root(a):
    return a ** 0.5

def absolute(a):
    return abs(a)

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def gcd(a,b):
    while b:
        a, b = b, a % b
    return a

def lcm(a,b):
    return a*b // gcd(a,b)