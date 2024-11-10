with open("A.txt") as A:
    content = A.read()
nums = content.split()
num = int(nums[0])
mul = int(nums[1])
with open("A.txt", "a") as A:
    for i in range(1, mul + 1):
        A.write(f"\n{num}*{i}={num * i}")