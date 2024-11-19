print("""
    1. January  
    2. February
    3. March
    4. April
    5. May
    6. June
    7. July
    8. August
    9. September
    10. October
    11. November
    12. December
""")

month = int(input("Enter month number: "))

if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
    print("Number of days: 31")
elif month == 4 or month == 6 or month == 9 or month == 11:
    print("Number of days: 30")
else:
    print("Number of days: 28/29")
