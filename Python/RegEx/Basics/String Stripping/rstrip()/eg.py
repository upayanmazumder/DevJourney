# Example program using rstrip()

# Original string with trailing whitespace
originalString = "Hello, World!   "

# Using rstrip() to remove trailing whitespace
strippedString = originalString.rstrip()

# Using rstrip() to remove specific trailing characters
strippedSpecificChars = originalString.rstrip("! ")

# Printing the results
print("Original string:", repr(originalString))
print("Stripped string (whitespace):", repr(strippedString))
print("Stripped string (specific chars '! '):", repr(strippedSpecificChars))

# Additional examples
# String with trailing characters to be stripped
exampleString = "!!!Hello, World!!!"

# Using rstrip() to remove trailing exclamation marks
strippedExclamations = exampleString.rstrip("!")

print("Example string:", repr(exampleString))
print("Stripped string (exclamations):", repr(strippedExclamations))