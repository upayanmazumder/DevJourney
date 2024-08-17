x=int(input("Please enter number 1 : "))
y=int(input("Please enter number 2 : "))
dec=int(input("Enter the number corresponding to the operation you wish to perform : \n1.Sum\n2.Difference\n3.Product\n4.Quotient\n5.Remainder\n"))
val=1
if(dec==1):
        res=x+y
elif(dec==2):
        res=x-y
elif(dec==3):
        res=x*y
elif(dec==4):
        res=x//y
elif(dec==5):
        res=x%y
else:
        val=0
if(val==1):
        print("Result is : ",res)
else:
        print("[Error] The number you have entered does not correspond to an option!")