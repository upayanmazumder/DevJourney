nums = []

# Populate the list
for i in range(10):
    n = int(input(f"Enter number {i+1}: "))
    while n<=0:
        print("Please enter a positive number!")
        n = int(input(f"Enter number {i+1}: "))
    nums.append(n)

# Sort in descending order
for i in range(len(nums)):
    for j in range(i + 1, len(nums)):
        if nums[i] < nums[j]:
            # Swap numbers
            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp

# New list with unique numbers
uNums = []
for num in nums:
    if num not in uNums:
        uNums.append(num)

if len(uNums) >= 3:
    print("The 3rd largest number is:", uNums[2])
else:
    print("Not enough unique numbers to find the 3rd largest.")
