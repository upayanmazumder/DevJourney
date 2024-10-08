# Check if the given password contains exactly 12 alpha numeric characters with at 
# least 1 special symbol and 1 Uppercase alphabet.

import re

s = input("Enter password: ")

if re.findall(r'[A-Z]',s) and re.findall(r'[!@#$%^&*]',s) and re.findall(r'[0-9]',s) and len(s)==12:
    print("Valid password")

else:
    print("Invalid password")
    if not re.findall(r'[A-Z]',s):
        print("Needs uppercase alphabets")
    if not re.findall(r'[!@#$%^&*]',s):
        print("Needs special characters")
    if not re.findall(r'[0-9]',s):
        print("Needs numbers")
    if not len(s)==12:
        print("Needs exactly 12 characters")
        