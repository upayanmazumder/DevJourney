n1 = int(input("Enter length of List 1: "))
n2 = int(input("Enter length of List 2: "))
l1,l2=[],[]

# Populate List 1
for i in range(n1):
    x = input(f"List 1: Enter element {i+1}: ")
    try:
        x = eval(x)
    except:
        pass    # Store as string
    l1.append(x)

# Populate List 2
for i in range(n2):
    x = input(f"List 2: Enter element {i+1}: ")
    try:
        x = eval(x)
    except:
        pass    # Store as string
    l2.append(x)

anyCommon=False

# Compare and print common elements
for i in range(n1):
    for j in range(n2):
        if l1[i] == l2[j]:
            print(l1[i], end=' ')
            anyCommon=True

if anyCommon==False:
    print("No common element") 
