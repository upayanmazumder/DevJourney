text = "apple,banana,cherry,orange,grape"
delimiter = ","
max_splits = 2

# Using rsplit() to split the string from the right
result = text.rsplit(delimiter, max_splits)

print(result)

# Output:
#####################
# ['apple,banana,cherry', 'orange', 'grape']