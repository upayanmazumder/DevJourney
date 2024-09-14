n=[]
t=[]
for i in range(10):
    j=int(input(f"Enter number {i+1}: "))
    n.append(j)
    if n[i]==0:
        t.append('neither odd nor even')
    elif n[i]%2==0:
        t.append('even')
    else:
        t.append('odd' )  
    
for i in range(10):
    print(f"{i+1}. {n[i]} is {t[i]}")
