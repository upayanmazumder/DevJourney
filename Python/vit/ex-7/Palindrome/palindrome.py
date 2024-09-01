n = str(input("Enter a number: "))
nL = len(n)  # Determine the length of the string representation of the number

isPal = True  # Initialize a flag to keep track of whether the number is a palindrome

# Iterate over the first half of the number
for i in range(nL // 2):  
    # Compare the i-th character from the start with the i-th character from the end
    if n[i] != n[nL - i - 1]:
        isPal = False  # If any characters don't match, set the flag to False
        break  # Exit the loop early since the number is not a palindrome

# Check the flag to determine if the number is a palindrome and print the result
if isPal:
    print(f"{n} is a palindrome.")  # Output if the number is a palindrome
else:
    print(f"{n} is not a palindrome.")  # Output if the number is not a palindrome
