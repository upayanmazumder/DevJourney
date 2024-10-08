import re
s = input("Enter statement: ")
res = re.search(r'\w+$',s)
print(res.group())