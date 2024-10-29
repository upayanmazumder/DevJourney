n=[]

for i in range(3):
    x=int(input(f'Enter {i+1}th number: '))
    n.append(x)

min=n[0]
max=n[0]
for i in range(3):
    if n[i]<min:
        min=n[i]
    if n[i]>max:
        max=n[i]

print(f'Max is {max} and min is {min}')
    
