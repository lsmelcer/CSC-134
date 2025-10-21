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

"""
This program solves the problem of calculating the sum of all natural numbers from 1 to n using recursion. 
The recursive function calls itself with smaller values of n until it reaches the base case (n = 1). At that 
point, the recursion stops and the function starts returning values back up the call stack, adding each number 
to the total. This approach demonstrates how problems can be broken into smaller parts and solved step by step 
using recursion.
"""
