import re

# Sample text
text = "The rain in Spain falls mainly in the plain."

# Regular expression pattern to find the word 'in'
pattern = r"\bin\b"

# Find all matches of the pattern in the text
matches = re.findall(pattern, text)

# Print the matches found
print("Matches found:", matches)