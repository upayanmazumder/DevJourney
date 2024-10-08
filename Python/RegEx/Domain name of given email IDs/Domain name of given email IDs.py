import re

s = str(input("Enter statement: "))
res = re.findall(r'@\w+[.][a-z.]+',s)
for i in res:
    print(i[1:])