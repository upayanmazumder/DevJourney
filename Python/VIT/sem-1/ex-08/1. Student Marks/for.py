mL = []
mT = 0

nSub = int(input("Enter the number of subjects: "))

for i in range(nSub):
    m = int(input(f"Enter the marks secured in subject {i + 1}: "))
    mL.append(m)
    mT += m

mAvg = mT / nSub

if mAvg > 80:
    sT = "an outstanding student"
elif mAvg > 50:
    sT = "an average student"
else:
    sT = "a slow learner"

print(f"The average mark is {mAvg} and the student is {sT}.")
