# Ask the user for the purchase price in cents
price = int(input("Enter the purchase price in cents (less than 100): "))

if price < 0 or price >= 100:
    print("Invalid input. Price must be between 0 and 99 cents.")

# Ben gave $1, which is 100 cents
change = 100 - price

# Calculate minimum coins for change
quarters = change // 25
change %= 25

dimes = change // 10
change %= 10

nickels = change // 5
change %= 5

pennies = change  # what's left are pennies

# Output in required format
print("Pennies (1 cent):", pennies)
print("Nickels (5 cents):", nickels)
print("Dimes (10 cents):", dimes)
print("Quarters (25 cents):", quarters)

"""
This program solves the problem of making change from a $1 bill when an item costs less than 100 cents.
It calculates how much change is needed by subtracting the item’s cost from 100. To return the fewest
coins, it uses a greedy approach: starting with the highest coin value (quarters), it figures out how
many of each coin (quarters, dimes, nickels, pennies) can be used without going over the remaining amount.
By subtracting each coin's total from the remaining change, it ensures the smallest number of coins is used.
"""
