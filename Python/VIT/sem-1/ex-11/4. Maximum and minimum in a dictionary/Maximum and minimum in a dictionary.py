# Maximum and minimum in a dictionary
d = {}

n = int(input("Enter length of dictionary: "))
for i in range(n):
    k = float(input(f"Enter {i+1}th key: "))
    v = float(input(f"Enter {i+1}th value: "))
    d[k] = v

lVal = list(d.values())

# Initialize valMax and valMin with the first value in the dictionary
valMax = lVal[0]
valMin = lVal[0]

# Iterate through the remaining values to find max and min
for val in lVal[1:]:
    if val > valMax:
        valMax = val
    if val < valMin:
        valMin = val

print(f"Max: {valMax}\nMin: {valMin}")
