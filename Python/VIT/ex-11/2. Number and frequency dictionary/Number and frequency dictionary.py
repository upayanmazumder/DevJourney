# Dictionary with key as number and value as frequency

n=int(input("How many numbers?: "))
l=[]
for i in range(n):
    x=int(input(f"Enter number {i+1}: "))
    l.append(x)
d={}
di={}
for i in range(n):
    di.clear
    count=0
    for j in range(n):
        if l[i]==l[j]:
            count+=1
    di.setdefault(l[i],count)
    d.update(di)

print(d)
    
    
    
