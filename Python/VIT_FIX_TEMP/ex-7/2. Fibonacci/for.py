n=int(input("Enter number of fibonacci numbers to print: "))

i=-1
j=1

for k in range(n):
    s=i+j
    i=j
    j=s
    print(s,end=' ')

