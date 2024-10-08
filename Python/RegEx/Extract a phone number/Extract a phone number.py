# Total digits = 10 ; Must start with either 6 or 7 or 8 or 9
import re

s = str(input("Enter statement: "))
res =  re.findall(r'[6-9]\d{9}',s)
print(res)