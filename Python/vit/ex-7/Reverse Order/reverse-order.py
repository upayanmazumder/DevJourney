n = int(input("Enter a number: "))
nRev = 0

# Reverse the number
while n > 0:
    r = n % 10
    nRev = nRev * 10 + r
    n = n // 10
print(nRev)
