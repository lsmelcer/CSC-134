# Get input from user
year = int(input("Enter a year: "))

# Divisible by 4 AND (not a century year OR divisible by 400)
if (year % 4 == 0) and ((year % 100 != 0) or (year % 400 == 0)):
    result = True
else:
    result = False
    
# Check if it's a leap year and print the result
print(result)

"""
This program solves the problem of determining whether a given year is a leap year using the exact rules 
of the Gregorian calendar. A year is a leap year if it is divisible by 4, but not if it is a century year 
(unless it is also divisible by 400). The code checks these conditions using if-else statements and returns 
True or False accordingly. This ensures accurate handling of both normal and century years, matching real-world 
leap year rules.
"""
