n = int(input("Enter number of terms: "))

if n <= 0:
    print("Please enter a positive integer.")
else:
    # Initialize the list with the first two Fibonacci numbers
    fib_numbers = [0, 1]
    
    # Generate Fibonacci numbers until the list has 'n' terms
    while len(fib_numbers) < n:
        # Calculate the next Fibonacci number by adding the last two numbers in the list
        next_fib = fib_numbers[-1] + fib_numbers[-2]
        # Append the next Fibonacci number to the list
        fib_numbers.append(next_fib)
    
    # Print the first 'n' Fibonacci numbers, joined by a comma
    print(", ".join(map(str, fib_numbers[:n])))
