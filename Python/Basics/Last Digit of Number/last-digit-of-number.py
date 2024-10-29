x=int(input("Enter a number: "))
while(x>0):
    d=x%10
    x=(x-d)/10
    d=int(d)
    print(d)
