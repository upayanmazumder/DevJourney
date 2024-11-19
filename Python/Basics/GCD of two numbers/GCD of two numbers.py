x = int(input("Enter x: "))
y = int(input("Enter y: "))

def find_factors(n):
    factors = []
    for i in range(1,n+1):
        if n % i == 0:
            factors.append(i)
    return factors

def gcd(x,y):
    xF = find_factors(x)
    yF = find_factors(y)
    gcd = 1
    for xTerm in xF:
        for yTerm in yF:
            if xTerm == yTerm:
                gcd = xTerm
    return gcd
   
print("GCD = ",gcd(x,y))