grade_points = {
    "S": 10,
    "A": 9,
    "B": 8,
    "C": 7,
    "D": 6,
    "E": 5,
    "F": 0
    }

num_subjects = int(input("Enter number of subjects: "))

total_credits = 0
total_weighted_points = 0

for i in range(1, num_subjects + 1):
    entry = input(f"Enter credit and grade for subject {i} (e.g., 3 S): ").strip().split()
    
    if len(entry) != 2:
        print("Invalid input. Skipping this subject.")
        continue
    
    try:
        credit = float(entry[0])
        grade = entry[1].upper()
    except:
        print("Invalid input. Skipping this subject.")
        continue

    if grade not in grade_points:
        print("Invalid grade. Skipping this subject.")
        continue

    total_credits += credit
    total_weighted_points += credit * grade_points[grade]

if total_credits == 0:
    print("No valid subjects entered. CGPA cannot be calculated.")
else:
    cgpa = total_weighted_points / total_credits
    print(f"\nYour CGPA is: {cgpa:.2f}")
