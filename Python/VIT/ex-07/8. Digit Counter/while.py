n = int(input("Enter a number: "))
dC = 0

while n > 0:
    dC += 1
    n //= 10

print("Digit Count:",dC)
