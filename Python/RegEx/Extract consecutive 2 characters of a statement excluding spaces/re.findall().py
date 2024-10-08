import re

s = str(input("Enter a string: "))
res = re.findall(r'\w{1,2}',s)
print(res)
