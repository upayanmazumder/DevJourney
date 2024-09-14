t=float(input("Enter total work hour: "))
r=float(input("Enter pay rate: "))
d=float(input("Enter deductions: "))
GP=t*r
NP=GP-d
print("Gross pay amount: {0}\nNet pay amount: {1}".format(GP,NP))