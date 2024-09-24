# Python program to check whether a key is present in a dictionary

d={}

# Populate the dictionary
n=int(input("Enter length of dictionary: "))
for i in range(n):
    k=eval(input(f"Enter {i+1}th key: "))
    v=eval(input(f"Enter {i+1}th value: "))
    d.update({k:v})
print("Dictionary: ",d)

present=False

# Find the key
x=eval(input("Enter key to find: "))
for i in d.keys():
    if x==i:
        print("Key Present!")
        present=True

if present==False:
    print("The key is not present in the dictionary!")
