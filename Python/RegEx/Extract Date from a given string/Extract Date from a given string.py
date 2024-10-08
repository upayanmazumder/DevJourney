import re

s = str(input("Enter statement: "))
res = re.findall(r'\d{1,2}[/\-.:]\d{1,2}[/\-.:](?:\d{4}|\d{2})', s)
print(res)