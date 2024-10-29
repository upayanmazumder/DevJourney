n=int(input("How many fibonacci numbers to print? :"))
f=[]
i=-1;j=1
while len(f)<n:
    s=i+j
    i=j
    j=s
    f.append(s)

if len(f)>0:
    print(f'{n} fibonacci numbers are: ')
    for i in range(len(f)):
        print(f[i],end=' ')
        if i<len(f)-1:
            print(',',end=' ')
else:
    print('No fibonacci numbers found')
