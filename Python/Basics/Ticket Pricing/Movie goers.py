# A movie theatre offers different ticket prices based on the age and type of
# movie. The prices are calculated as follows:
# Children (age 0 to 12) for a regular movie: $7
# Children (age 0 to 12) for a 3D movie: $9
# Adults (age 13 and above) for a regular movie: $10
# Adults (age 13 and above) for a 3D movie: $12
# Additionally, for groups of 5 or more, there's a 10% discount on the total cost. Write an
# algorithm, python code, and draw a flowchart, that takes the age of the moviegoer,
# the movie type (regular or 3D), and the number of people in the group as input, and
# calculates the total cost after applying any applicable discounts

n=int(input("Enter number of moviegoers: "))
cT=0

tp=int(input("Enter the number corresponding to the type of movie: \n\t1. Regular Movie\n\t2. 3D Movie\nMovie type: "))
while tp not in (1,2):
    print("Invalid Input! Supported inputs are 1 and 2")
    tp=int(input("Enter the number corresponding to the type of movie: \n\t1. Regular Movie\n\t2. 3D Movie\nMovie type: "))

print("Selected",end=' ')  
if tp==1:
    t=0
    print("Regular Movie")
elif tp==2:
    t=2
    print("3D Movie")


for i in range(n):
    age=int(input(f'Enter age of {i+1}th moviegoer: '))
    while age<0:
        print("Age cannot be negative!")
        age=int(input(f'Enter age of {i+1}th moviegoer: '))
    if age<13:
        cost=7+t
    else:
        cost=10+t
    cT+=cost

if n>=5:
    cT=0.9*cT

print(f"Total cost={cT}")



    
