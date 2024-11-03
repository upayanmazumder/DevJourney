S = {'a', 'b', 'c'}
O = []

for x in S:
    for y in S:
        for z in S:
            O.append(x + y + z)

print(O)