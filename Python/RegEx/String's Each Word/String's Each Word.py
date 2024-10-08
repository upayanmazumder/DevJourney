import re

s = str(input("Enter statement: "))
res = re.findall(r'\w+',s)
print(res)