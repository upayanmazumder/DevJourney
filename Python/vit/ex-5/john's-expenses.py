# Define John's annual salary and percentage for gifts
s = 1200000
giftP = 10

# Calculate the allotted amount for gifts
giftT = (giftP / 100) * s

# Amount spent on gifts
mDay = 25000
vDay = 50000
bDay = 15000

# Calculate total expenditure on gifts
totExp = mDay +vDay + bDay

# Check if expenditure exceeds the allotted amount
if totExp > giftT:
    print("John's expenditure on gifts has exceeded the allotted amount.")
else:
    print("John's expenditure on gifts is within the allotted amount.")
