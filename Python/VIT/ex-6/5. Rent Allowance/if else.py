s=int(input("Enter salary: Rs."))
actR=int(input("Enter rent: Rs."))

maxR=6/100*s

if actR<=maxR:
    print("Rent allowance matched")
else:
    print("Rent allowance not matched")