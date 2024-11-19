y = int(input("Enter year: "))
r = y%4
if r:
    print("Not a leap year")
else:
    print("Leap year")