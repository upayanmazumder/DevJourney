d1 = { 'a' : 100, 'b' : 200, 'c' : 300 }
d2 = { 'a' : 300, 'b' : 200, 'd' : 400 }
d3 = {}

# First make a list d3 with common keys
d3.update(d1)
d3.update(d2)

# Update the values of common keys
for i in d1.keys():
    for j in d2.keys():
        if i == j:
            d3[i] += d1[i]

# Print final dictionary
print(d3)