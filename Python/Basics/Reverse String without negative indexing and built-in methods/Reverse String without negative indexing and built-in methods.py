s = input("Enter string: ")
l = []

for char in s:
    l.append(char)

for i in range(len(l)):
    print(l.pop(), end="")