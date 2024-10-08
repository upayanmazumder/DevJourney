import re

s = str(input("Enter statement: "))
res = re.findall(r'\b\w{2}',s)
print(res)