import re

str = input("Enter a string: ")
rePat = 'ab{3}'
if re.findall(rePat, str):
    print("String has an a followed by 3 bs")
else:
    print("String does not have an a followed by 3 bs")