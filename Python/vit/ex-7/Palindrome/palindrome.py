n = int(input("Enter a number: "))
original = n  # Store the original number
reversed_num = 0

# Reverse the number
while n > 0:
    remainder = n % 10
    reversed_num = reversed_num * 10 + remainder
    n = n // 10

# Compare the original number with the reversed number
if original == reversed_num:
    print(f"{original} is a palindrome.")
else:
    print(f"{original} is not a palindrome.")
