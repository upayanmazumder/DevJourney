n = int(input("How many numbers: "))
l = []
for i in range(n):
    num = int(input(f"Enter number {i+1}: "))
    l.append(num)
print(l)

i = 0
sum = 0

def sum_of_list(l):
    if len(l) == 1:
        return l[0]
    else:
        return l[0] + sum_of_list(l[1:])
    
res = sum_of_list(l)
print(res)    