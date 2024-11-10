import re

str = input("Enter a string: ")
rePat = r'[A-Z][a-z]+'
l = re.findall(rePat, str)
print(l)