import re

s = input("Enter statement: ")
reg = r'\w+'
res = re.match(reg,s)
print(res.group())