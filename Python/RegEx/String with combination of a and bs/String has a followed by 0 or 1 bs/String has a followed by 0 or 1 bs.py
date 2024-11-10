import re

str = input("Enter a string: ")
rePat = r'ab?'
if re.findall(rePat, str):
    print("Valid")
else:
    print("Invalid")