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