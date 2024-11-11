n = int(input("Enter number: "))

def fact(n):
    if n==1:
        return 1
    else:
        return n * fact(n-1)
    
res = fact(n)
print(res)