import re

result = re.match(r'NG','NG Swetha NG Swetha')
print(result)
print(result.group())
print(result.span())
print(result.start())
print(result.end())
print(result.string)

# Output:
"""
<re.Match object; span=(0, 2), match='NG'>
NG
(0, 2)
0
2
NG Swetha NG Swetha
"""