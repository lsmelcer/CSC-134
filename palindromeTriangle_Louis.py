# Ask user for a positive integer
N = int(input("Enter the size of the palindromic triangle (positive integer): "))

if N <= 0:
    print("Please enter a number greater than 0.")

# Loop to print each row of the triangle
for i in range(1, N + 1):
    # Print left side (1 to i)
    for j in range(1, i + 1):
        print(j, end='')

    # Print right side (i-1 down to 1)
    for j in range(i - 1, 0, -1):
        print(j, end='')

    # Move to the next line
    print()

"""
This program solves the problem of printing a palindromic triangle of size N, where each row is a number 
pattern that reads the same forward and backward. For each row number i, the program first prints numbers 
from 1 to i, then prints numbers from i-1 back down to 1. This forms a symmetric (palindromic) number 
pattern. Using nested loops, the program builds and prints each line, fulfilling the requirement exactly.
"""
