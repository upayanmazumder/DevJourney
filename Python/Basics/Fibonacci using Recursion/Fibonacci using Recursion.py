def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

l = []
n = int(input("How many numbers: "))

for i in range(n):
    l.append(fib(i))
    
print(l)