for i in range(5, 0, -1):  # Outer loop starts from 5 and decreases down to 1
    for j in range(i, 0, -1):  # Inner loop prints numbers from current i down to 1
        print(j, end=' ')  # Print numbers on the same line separated by spaces
    print()  # Move to the next line after printing each row
