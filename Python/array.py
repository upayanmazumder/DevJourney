# Get the number of numbers from the user
num_of_numbers = int(input("Enter the number of numbers: "))

# Initialize variables for sum and average
total_sum = 0
average = 0

# Get the numbers from the user and calculate sum
for i in range(num_of_numbers):
    number = int(input("Enter " + str(i+1) + "th number: "))
    total_sum += number

# Calculate average
if num_of_numbers > 0:
    average = total_sum / num_of_numbers

# Print the sum and average
print("Sum:", total_sum)
print("Average:", average)