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