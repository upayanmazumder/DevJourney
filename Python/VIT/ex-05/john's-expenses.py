s = 1200000
giftP = 10

giftT = (giftP / 100) * s

# Amount spent on gifts
mDay = 25000
vDay = 50000
bDay = 15000

# Calculate total expenditure
totExp = mDay +vDay + bDay

if totExp > giftT:
    print("John's expenditure on gifts has exceeded the allotted amount.")
else:
    print("John's expenditure on gifts is within the allotted amount.")
