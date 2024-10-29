x=int(input("Enter a number: "))
xOrg=x
xRev=0

while x:
    r=x%10
    xRev=r+xRev*10
    x=x//10

print("Palindrome") if xOrg==xRev else print("Not a palindrome")
    
