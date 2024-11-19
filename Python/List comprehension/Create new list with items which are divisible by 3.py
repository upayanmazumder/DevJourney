n = int(input("How many numbers: "))
l = []

for i in range(n):
    num = int(input(f"Enter number {i+1}: "))
    l.append(num)

print("Original list: ",l)

lN = [i for i in l if i % 3 == 0]

print("New list", lN)