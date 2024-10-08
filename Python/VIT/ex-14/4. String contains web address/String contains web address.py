import re

s = input("Enter statement: ")
res = re.findall(r'(https?://(?:[-\w.]|(?:%[\da-fA-F]{2}))+)', s)
if res:
    print(res, "is a valid web address!")
else:
    print("Not a valid web address!")
