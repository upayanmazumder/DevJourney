import pandas as pd
import numpy as np

# The Pandas Dataframe
num_students = 5
data = {
    'Registration Number': [],
    'Student Name': [],
    'Registered Credits': []
}

for _ in range(num_students):
    reg_no = input("Enter Registration Number: ")
    name = input("Enter Student Name: ")
    credits = float(input("Enter Registered Credits: "))
    data['Registration Number'].append(reg_no)
    data['Student Name'].append(name)
    data['Registered Credits'].append(credits)

df = pd.DataFrame(data)
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

matrix = np.array(matrix)
print("\nNumpy Array (Matrix):\n", matrix)