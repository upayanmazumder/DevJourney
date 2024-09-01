n = str(int(input("Enter a number: ")))

nLen = len(n)

# Calculate the Armstrong sum
nArmSum = sum(int(digit) ** nLen for digit in n)

# Check if the Armstrong sum equals the original number
if nArmSum == n:
    print(f"{n} is an Armstrong number.")
else:
    print(f"{n} is not an Armstrong number.")
