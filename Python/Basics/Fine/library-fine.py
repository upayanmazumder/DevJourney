d=int(input("Enter days late: "))

if d>30:
    print("Membership cancelled!")
    
elif d==0:
    print("No fine!")

else:
    if d<=5:
        f=0.5
    elif d>=6 and d<=10:
        f=1
    else:
        f=5
    print("Fine is Rs. ",f)
        
