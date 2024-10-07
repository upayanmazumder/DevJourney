import re

# Sample text to search
sampleText = "The quick brown fox jumps over the lazy dog."

# Regular expression pattern to search for
pattern = r"quick"

# Using re.search to find the pattern in the sample text
match = re.search(pattern, sampleText)

# Check if a match is found
if match:
    print(f"Match found: {match.group()}")
    print(f"Match starts at index: {match.start()}")
    print(f"Match ends at index: {match.end()}")
else:
    print("No match found.")


# Output:
"""
Match found: quick
Match starts at index: 4
Match ends at index: 9
"""