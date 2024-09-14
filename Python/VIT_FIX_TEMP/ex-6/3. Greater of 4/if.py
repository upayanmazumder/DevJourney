a=float(input("Enter no. 1: "))
b=float(input("Enter no. 2: "))
c=float(input("Enter no. 3: "))
d=float(input("Enter no. 4: "))

greatest = a
if b > greatest:
    greatest = b
if c > greatest:
    greatest = c
if d > greatest:
    greatest = d

print("The greatest number is:", greatest)
