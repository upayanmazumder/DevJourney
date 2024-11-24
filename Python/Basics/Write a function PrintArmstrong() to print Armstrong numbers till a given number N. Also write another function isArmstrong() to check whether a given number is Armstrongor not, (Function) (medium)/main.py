# Write a function PrintArmstrong() to print Armstrong numbers till a given number
# N. Also write another function isArmstrong() to check whether a given number is
# Armstrong or not, (Function) (medium)

def isArmstrong(n):
    org = n
    sum = 0
    while n > 0:
        rem = n % 10
        cube = rem ** 3
        sum += cube
        n = n // 10
    if sum == org:
        return True
    else:
        return False
    
def PrintArmstrong(n):
    l = []
    for i in range(n):
        if isArmstrong(i):
            l.append(i)
    return l
    
x = int(input("Enter number to check: "))

print("Yes," if isArmstrong(x) else "No", "Armstrong numbers till",x,"are: ",end="")

ans = PrintArmstrong(x)

for i in range(len(ans)):
    print(ans[i], end = ',' if i + 1  < len(ans) else '')
