def combine_dictionaries(d1, d2):
    combined_dict = d1.copy()  # Start with a copy of the first dictionary
    for key, value in d2.items():
        if key in combined_dict:
            combined_dict[key] += value  # Add values for common keys
        else:
            combined_dict[key] = value  # Add new key-value pairs
    return combined_dict

# Example dictionaries
d1 = {'a': 100, 'b': 200, 'c': 300}
d2 = {'a': 300, 'b': 200, 'd': 400}

# Combine dictionaries
result = combine_dictionaries(d1, d2)
print(result)