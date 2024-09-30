n = int(input("Enter the number of elements in the set: "))
l = []
for i in range(n):
    l.append(eval(input(f"Element {i+1}: ")))
s = set(l)
x = eval(input("Enter the element to search: "))
if x in s:
    print("Element found")
else:
    print("Element not found")