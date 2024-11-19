n = 3
s = []

for i in range(n):
    side = int(input(f"Enter side {i+1}: "))
    s.append(side)

if s[0] == s[1] == s[2]:
    print("Equilateral Triangle")
elif s[0] == s[1] or s[1] == s[2] or s[2] == s[0]:
    print("Isosceles Triangle")
else:
    print("Scalene Triangle")