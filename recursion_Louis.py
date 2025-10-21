# Get user input
n = int(input("Enter a positive integer: "))

def sum_natural(n):
    # Base case: if n is 1, return 1
    if n == 1:
        return 1
    else:
        # Recursive case: n + sum of numbers before it
        return n + sum_natural(n - 1)

if n <= 0:
    print("Please enter a number greater than 0.")

# Call the function and print the result
result = sum_natural(n)
print("Sum from 1 to", n, "is:", result)