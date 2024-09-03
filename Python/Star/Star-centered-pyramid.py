i=0
while i<=3: #Each line 1-4
    j=0
    while j<=(2-i): #Preceding space for each line
        print(" ", end=" ")
        j+=1
    i+=1
    k=0
    while k<=(2*i-2):
        print("*",end=" ")
        k+=1
    print()
