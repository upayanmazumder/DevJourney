import re

String = """
1.Ramesh has completed by B.E in CSE at VIT and M.E in CSE at MIT.
2.Suresh has completed by B.E in CSE at Anna University and M.E in CSE at VIT.
3.Rajesh has completed by B.E in CSE at Anna University and M.E in CSE at Anna
University.
"""

resPat = r'\d.+VIT'
res = re.findall(resPat,String)

namesPat = r'[A-Z][a-z]+'
names = []
for line in res:
    name = re.search(namesPat, line)
    names.append(name[0])

print(names)