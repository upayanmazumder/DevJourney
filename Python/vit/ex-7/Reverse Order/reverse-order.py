# Prompt the user to enter a number
number = input("Enter a number: ")

# Initialize an empty string to store the reversed number
reversed_number = ''

# Iterate over each digit in the original number
for digit in number:
    # Prepend each digit to the reversed_number string
    reversed_number = digit + reversed_number

# Print the reversed order of the number
print("Reversed order:", reversed_number)
