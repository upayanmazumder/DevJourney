import re
str = input("Enter string: ")
rePat = r'[A-Za-z0-9]'
if re.findall(rePat, str):
    print("String contains only A-Za-z0-9")
else:
    print("String contains other characters")