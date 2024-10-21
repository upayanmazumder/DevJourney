import re
import requests

url = input("Enter the URL of the site to scrape: ")
response = requests.get(url)
response.raise_for_status()
html_content = response.text

# Modify the regex to capture the slash if it's a closing tag
tags = re.findall(r'<\s*(/?)\s*([a-zA-Z0-9]+)', html_content)

print("HTML tags found on the site:")
for tag in tags:
    # If the first capture group is '/', it's a closing tag
    if tag[0] == '/':
        print(f"</{tag[1]}>")
    else:
        print(f"<{tag[1]}>")
