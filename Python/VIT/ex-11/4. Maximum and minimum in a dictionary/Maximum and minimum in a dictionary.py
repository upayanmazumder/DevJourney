# Maximum and minimum in a dictionary
d = {}

n = int(input("Enter length of dictionary: "))
for i in range(n):
    k = float(input(f"Enter {i+1}th key: "))
    v = float(input(f"Enter {i+1}th value: "))
    d[k] = v

print(d)

lVal = list(d.values())

# Initialize max_val and min_val with the first value in the dictionary
max_val = lVal[0]
min_val = lVal[0]

# Iterate through the remaining values to find max and min
for val in lVal[1:]:
    if val > max_val:
        max_val = val
    if val < min_val:
        min_val = val

print(f"Max: {max_val}\nMin: {min_val}")
