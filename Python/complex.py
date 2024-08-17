x=str(input("Enter a complex number: "))
r=complex(x).real
i=complex(x).imag
if(i==0):
    type="real"
else:
    type="complex"
print("The number {0} is a {1} number.".format(x,type))
if(r!=0):
    print("Real part: {0}".format(r))
if(i!=0):
    print("Imaginary part: {0}".format(i))