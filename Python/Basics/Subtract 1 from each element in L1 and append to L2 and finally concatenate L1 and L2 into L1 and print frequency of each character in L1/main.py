L1=[1,2,3,4,5]
L2 = []

for i in range(len(L1)):
    res = L1[i] - 1
    L2.append(res)

print(f"L1 : {L1}\nL2 : {L2}")

L1 += L2

print(f"\nPost concatenation:\nL1: {L1}")

def get_frequency(l,item):
    count = 0
    for i in l:
        if i == item:
            count += 1
    return count

for item in set(L1): # Use set to prevent repeatation
    print(f"{item} has frequency {get_frequency(L1,item)}")