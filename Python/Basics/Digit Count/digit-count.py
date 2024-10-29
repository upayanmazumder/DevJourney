n=int(input("Enter a number: "))
i=0   
while n:
    i+=1
    n=n//10
if i<3:
    print(f"The number has {i} digits")

else:
    print("The number has more than 3 digits")
