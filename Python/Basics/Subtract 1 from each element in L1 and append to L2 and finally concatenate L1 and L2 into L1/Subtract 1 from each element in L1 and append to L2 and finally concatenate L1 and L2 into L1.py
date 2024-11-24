L1=[1,2,3,4,5]
L2 = []

for i in range(len(L1)):
    res = L1[i] - 1
    L2.append(res)

print(f"L1 : {L1}\nL2 : {L2}")

L1 += L2

print(f"\nPost concatenation:\nL1: {L1}")