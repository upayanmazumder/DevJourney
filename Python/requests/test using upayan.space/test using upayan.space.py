import requests as r
import re

res = r.get('https://upayan.space')
print(res.text)
repat = r'[<].*?[>]'
tags = re.findall(repat, res.text)
print('\n\n\n')
for tag in tags:
    print(tag)