import re 

str = input("Enter a string: ")
rePat = r'[a-z]+[_][a-z]+'
if re.findall(rePat, str):
    print("Valid")
else:
    print("Invalid")