import re

s = input("Enter statement: ")
res = re.findall(r'ab*',s)
print(res)