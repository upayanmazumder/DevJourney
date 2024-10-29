import re 
import requests as r

url = input('Enter the URL: ')
res = r.get(url)
repat = r'[<].*?[>]'
tags = re.findall(repat, res.text)
print('\n\n\n')
print('Tags in the given site are: ')
for tag in tags:
    print(tag)