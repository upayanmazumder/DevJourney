import re

result = re.match(r'NG','NG Swetha NG Swetha')
print(result)

result = re.match('NG','NG Swetha')
print(result)

result = re.match('NG','Swetha')
print(result)

result = re.match('NG','Swetha NG Swetha')
print(result)

# Output:
"""
<re.Match object; span=(0, 2), match='NG'>
<re.Match object; span=(0, 2), match='NG'>
None
None
"""