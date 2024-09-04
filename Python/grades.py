m=int(input("Enter marks: "))
if m>80:
    g='A'
elif m>60 and m<=80:
    g='B'
elif m>50 and m<=60:
    g='C'
elif m>45 and m<=50:
    g='D'
elif m>=25 and m<=45:
    g='E'
elif m<25:
    g='F'

print("Grades: ",g)
