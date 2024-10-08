import re

s = input("Enter statement: ")
res = re.findall(r'[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}', s)

if res:
    print("Valid email(s) found:")
    for email in res:
        print(email)
else:
    print("No valid email found.")