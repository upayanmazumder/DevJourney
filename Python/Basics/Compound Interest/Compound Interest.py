
P=int(input("Enter Principal Amount: "))
R=int(input("Enter Rate of Interest: "))
t=int(input("Enter time: "))

A=P * (1 + R/100)**t

CI=A-P

print(f'Compound interest is {CI}')