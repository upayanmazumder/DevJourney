n=int(input("How many numbers?: "))
l=[]

# Populate the list
for i in range(n):
    x=int(input(f"Enter number {i+1}: "))
    l.append(x)

d={}
di={}

# Populate the dictionary
for i in range(n):
    di.clear
    count=0
    for j in range(n):
        if l[i]==l[j]:
            count+=1
    di.setdefault(l[i],count)
    d.update(di)

print(d)