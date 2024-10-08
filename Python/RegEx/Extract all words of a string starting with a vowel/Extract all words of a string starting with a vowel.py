import re 

s = str(input("Enter statement: "))
res = re.findall(r'\b[aeiouAEIOU]\w*',s)
print(res)