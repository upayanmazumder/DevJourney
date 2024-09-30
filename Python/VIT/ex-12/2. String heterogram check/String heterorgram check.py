s = str(input("Enter a string:"))
lStr=len(s)

s = set(s)
lSet=len(s)

if lStr == lSet:
    print("Heterogram")
else:
    print("Not a heterogram")