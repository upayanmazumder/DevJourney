x = int(input("Enter a number: "))
org = x

# Get list of digits
digits = []
while x > 0:
    rem = x % 10
    if org % rem == 0:
        digits.append(rem)
    x = x // 10

# Create the string
s = ""
for digit in digits:
    s += str(digit)
    s += " "

print(s)