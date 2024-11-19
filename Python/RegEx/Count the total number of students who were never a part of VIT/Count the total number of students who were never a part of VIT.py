import re

String = """
1.Ramesh has completed by B.E in CSE at VIT and M.E in CSE at MIT.
2.Suresh has completed by B.E in CSE at Anna University and M.E in CSE at VIT.
3.Rajesh has completed by B.E in CSE at Anna University and M.E in CSE at Anna
University.
"""

linesPat = r'.*VIT.*'
lines = re.findall(linesPat,String)
print(f"{len(lines)} students")