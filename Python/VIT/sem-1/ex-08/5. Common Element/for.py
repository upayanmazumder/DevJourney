n1 = int(input("Enter length of List 1: "))
n2 = int(input("Enter length of List 2: "))
l1,l2,lC=[],[],[]

# Populate List 1
print("List 1 >>")
for i in range(n1):
    x = str(input(f"\tEnter element {i+1}: "))
    l1.append(x)

# Populate List 2
print("List 2 >>")
for i in range(n2):
    x = str(input(f"\tEnter element {i+1}: "))
    l2.append(x)

# Compare and print common elements
for i in range(n1):
    for j in range(n2):
        if l1[i] == l2[j]:
            lC.append(l1[i])

if len(lC)==0:
    print("No common elements")
else:
    print("Common element(s):",end=' ')
    for i in range(len(lC)):
        print(lC[i], end = '')
        if i<len(lC)-1:
            print(',',end='')
