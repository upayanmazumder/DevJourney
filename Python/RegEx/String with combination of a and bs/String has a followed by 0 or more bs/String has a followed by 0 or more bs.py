import re

str = input("Enter a string: ")
rePat = r'ab*'
if re.findall(rePat,str):
    print("String has an a followed by 0 or more bs")
else:
    print("String does not have an a followed by 0 or more bs")