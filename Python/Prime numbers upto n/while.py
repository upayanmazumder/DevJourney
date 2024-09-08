n=int(input("How many prime numbers required? : "))
p=[]
i=1

while len(p)<n:     # Until list is complete
    i+=1    # Consider a new number
    j=2
    div=False
    while j<i:  # Each number between 2 to the prev of considered number
        if i%j==0:
            div=True
        j+=1
    if div==False:
        p.append(i)

print(p)
            
    
