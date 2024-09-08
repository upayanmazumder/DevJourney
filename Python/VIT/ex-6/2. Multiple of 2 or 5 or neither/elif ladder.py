x = int(input("Enter a number: "))
print(f"The number {x} is divisible by", end=' ')
if x % 2 == 0 and x % 5 == 0:
    print("both 2 and 5")
elif x % 2 == 0 and x % 5 != 0:
    print("only 2")
elif x % 2 != 0 and x % 5 == 0:
    print("only 5")
else:
    print("neither 2 nor 5")