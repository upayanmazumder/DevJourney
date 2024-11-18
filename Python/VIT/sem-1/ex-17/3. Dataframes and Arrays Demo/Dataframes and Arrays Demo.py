import pandas as p
import numpy as n

# The Pandas Dataframe
data = {
    'Registration Number': [],
    'Student Name': [],
    'Registered Credits': []
}
x = 5
for student in range(x):
    regNo = input("Enter Registration Number: ")
    name = input("Enter Student Name: ")
    credits = float(input("Enter Registered Credits: "))
    data['Registration Number'].append(regNo)
    data['Student Name'].append(name)
    data['Registered Credits'].append(credits)

df = p.DataFrame(data)
print("Pandas DataFrame:\n", df)

# The Numpy array
rows = 3
cols = 3
matrix = []

for i in range(rows):
    row = []
    for j in range(cols):
        value = int(input(f"Enter the value for element ({i+1}, {j+1}): "))
        row.append(value)
    matrix.append(row)

matrix = n.array(matrix)
print("\nNumpy Array (Matrix):\n", matrix)