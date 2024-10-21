import re

s = input("Enter statement: ")
res = re.findall(r'(https?://(?:[-\w.]|(?:%[\da-fA-F]{2}))+)', s)
if res:
    print("Valid web address : ",res,)
else:
    print("Not a valid web address!")
