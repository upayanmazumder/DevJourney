import re

str = input("Enter a string: ")
rePat = r'ab{2,3}'
if re.findall(rePat,str):
    print("String has an a followed by 2 or 3 bs")
else:
    print("String does not have an a followed by 2 or 3 bs")