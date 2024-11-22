x = 5

for row in range(x, 0, -1):
    for space in range(x-row):
        print(" ", end=" ")
    for item in range(1, row + 1):
        print(item, end=" ")
    print()