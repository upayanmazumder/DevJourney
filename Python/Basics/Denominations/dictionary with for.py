# Prompt the user to enter an amount to be broken down into currency denominations
amount = int(input("Enter the amount: "))

# Dictionary to store the count of each denomination
# Key: denomination value, Value: count of notes of that denomination
notes = {
    500: 0,
    200: 0,
    100: 0,
    50: 0,
    20: 0,
    10: 0,
    5: 0,
    2: 0,
    1: 0
}

# Loop through each denomination in the dictionary
for note in notes:
    # If the amount is greater than or equal to the denomination
    if amount >= note:
        # Calculate the number of notes of this denomination
        notes[note] = amount // note
        # Update the amount with the remainder after using the above notes
        amount = amount % note

# Print the denomination breakdown
print("Denomination breakdown:")

# Loop through the dictionary to print each denomination and its count
for note, count in notes.items():
    # Only print denominations that are used (i.e., count > 0)
    if count > 0:
        print(f"Rs. {note}: {count} note(s)")
