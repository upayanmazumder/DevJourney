# Example program using lstrip()

# Original string with leading whitespace
originalString = "   Hello, World!   "

# Using lstrip() to remove leading whitespace
strippedString = originalString.lstrip()

# Using lstrip() to remove specific leading characters
strippedSpecificChars = originalString.lstrip(" H")

# Printing the results
print("Original string:", repr(originalString))
print("Stripped string (whitespace):", repr(strippedString))
print("Stripped string (specific chars ' H'):", repr(strippedSpecificChars))

# Additional examples
# String with leading characters to be stripped
exampleString = "!!!Hello, World!!!"

# Using lstrip() to remove leading exclamation marks
strippedExclamations = exampleString.lstrip("!")

print("Example string:", repr(exampleString))
print("Stripped string (exclamations):", repr(strippedExclamations))