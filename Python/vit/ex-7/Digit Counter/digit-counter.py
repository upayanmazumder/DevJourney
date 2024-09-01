n = int(input("Enter a number: "))
digCount = 0

#Increment digit count for each digit in the number
while n > 0:
    digCount += 1
    n //= 10

print("Digit Count:",digCount)
