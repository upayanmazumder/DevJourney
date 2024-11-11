n = int(input("Enter number of steps: "))

def walk(steps):
    if steps == 0:
        return
    else:
        walk(steps-1)
        print(f"Walk #{steps}")

walk(n)