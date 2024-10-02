import re

text = str(input("Enter a string: "))
v = re.findall(r'[aeiouAEIOU]', text)
vC = len(v)
print(f"There are {vC} vowels in the string: {text}")