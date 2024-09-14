n = int(input("Enter a number: "))
nOrg = n
nRev = 0

# Reverse the number
while n > 0:
    r = n % 10
    nRev = nRev * 10 + r
    n = n // 10

if nOrg == nRev:
    print(f"{nOrg} is a palindrome.")
else:
    print(f"{nOrg} is not a palindrome.")
