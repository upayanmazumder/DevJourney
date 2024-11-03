d={}

# Populate the dictionary
n=int(input("Enter length of dictionary: "))

for i in range(n):
    k=eval(input(f"Enter {i+1}th key: "))
    v=eval(input(f"Enter {i+1}th value: "))
    d.update({k:v})

# Find the key
present=False   # Flag to check if key is present

x=eval(input("Enter key to find: "))

for i in d.keys():
    if x==i:
        print("Key Present!")
        present=True

if present==False:
    print("The key is not present in the dictionary!")