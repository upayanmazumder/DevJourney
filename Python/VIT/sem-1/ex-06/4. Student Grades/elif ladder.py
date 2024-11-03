m=int(input("Enter marks: "))
if m>=91:
    print("Grade: S")
elif m>=81 and m<=90:
    print("Grade: A")
elif m>=71 and m<=80:
    print("Grade: B")
elif m>=61 and m<=70:
    print("Grade: C")
elif m>=51 and m<=60:
    print("Grade: D")
elif m==50:
    print("Pass")
elif m<50:
    print("Fail")