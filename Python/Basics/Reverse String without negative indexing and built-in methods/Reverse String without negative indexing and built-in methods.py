s = input("Enter string: ")
l = []

for char in s:
    l.append(char)

i = len(l) - 1

while i >= 0:
    print(l[i], end="")
    i -= 1
