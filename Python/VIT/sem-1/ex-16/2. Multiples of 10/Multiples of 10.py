n = 10
l = []
for i in range(10):
    prod = 10 * (i + 1)
    l.append(prod)

file = open('file.txt', 'w')
file.write(str(l))
file.close()