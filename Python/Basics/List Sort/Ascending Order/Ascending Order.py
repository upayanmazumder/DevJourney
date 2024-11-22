l = [2,3,4,6,1,2,3,6,10,2]
n = 10
s = []

min = l[0]

for i in range(len(l)):
    for j in range(0, len(l) - i - 1):
        if l[j] > l[j + 1]:
            l[j], l[j + 1] = l[j + 1], l[j]

print(l)
