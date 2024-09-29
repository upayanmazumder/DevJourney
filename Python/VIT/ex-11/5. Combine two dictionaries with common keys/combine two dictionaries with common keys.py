d1 = { 'a' : 100, 'b' : 200, 'c' : 300 }
d2 = { 'a' : 300, 'b' : 200, 'd' : 400 }
di={}
for k1 in d1.keys():  # For each key in d1
    for k2 in d2.keys():  # For each key in d2
        foundk2=False # Initialize found to False
        di.clear() # Initialise mini dictionary
        if k1 == k2:    # If the keys are the same
            d1[k1] += d2[k2]    # Add the values of the keys and store in d1
            foundk2=True # Set found to True for the key in d2
        if not foundk2: # If foundk2 is False
            di.setdefault(k2,d2[k2]) # If found is True, add the key and value to dictionary
            d1.update(di)  # Update d1 with the key and value in di

# Incomplete