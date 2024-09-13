t1=(1, 2, 3, 4)
t2=(3, 5, 2, 1)
t3=(2, 2, 3, 1)

n=[]

for i in range(4):
    n.append(t1[i]+t2[i]+t3[i])

t=(n[0],n[1],n[2],n[3])

print(t)