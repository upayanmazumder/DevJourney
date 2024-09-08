n=int(input("How many fibonacci numbers to print? :"))
f=[]
i=-1;j=1
while len(f)<n:
    s=i+j
    i=j
    j=s
    f.append(s)
print(f)
    
