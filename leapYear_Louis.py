# Get input from user
year = int(input("Enter a year: "))

# Divisible by 4 AND (not a century year OR divisible by 400)
if (year % 4 == 0) and ((year % 100 != 0) or (year % 400 == 0)):
    result = True
else:
    result = False
    
# Check if it's a leap year and print the result
print(result)