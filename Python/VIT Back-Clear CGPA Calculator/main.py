import re

# Grade points mapping
grade_points = {
    'S': 10,
    'A': 9,
    'B': 8,
    'C': 7,
    'D': 6,
    'E': 5,
    'F': 0  # F is ignored for current CGPA
}

def parse_semester(input_lines):
    sem_credits = 0.0
    sem_weighted = 0.0
    failed_credits = 0.0

    for line in input_lines:
        line = line.strip()
        if not line or line.startswith("Sl.No.") or re.match(r"L\s+P\s+J\s+C", line):
            continue

        # Try to parse: last numeric before grade is credit, last non-space char is grade
        parts = line.split()
        if len(parts) < 2:
            continue
        # find credit (usually 4th float from left)
        credit = None
        grade = None
        floats = [float(p) for p in parts if re.match(r'^\d+(\.\d+)?$', p)]
        if floats:
            credit = floats[-1]
        grade_match = re.findall(r'\b([SABCDEF])\b', line)
        if grade_match:
            grade = grade_match[-1]

        if credit is not None and grade:
            if grade == 'F':
                failed_credits += credit
            else:
                sem_credits += credit
                sem_weighted += credit * grade_points[grade]

    gpa = sem_weighted / sem_credits if sem_credits > 0 else 0
    return sem_credits, sem_weighted, failed_credits, gpa

def main():
    n = int(input("Enter number of semesters: "))
    semester_data = []

    for i in range(n):
        print(f"\nPaste data for Semester {i+1} (end with empty line twice):")
        lines = []
        blank_count = 0
        while True:
            line = input()
            if line.strip() == "":
                blank_count += 1
                if blank_count == 2:
                    break
            else:
                blank_count = 0
                lines.append(line)
        sem_credits, sem_weighted, failed_credits, gpa = parse_semester(lines)
        semester_data.append((sem_credits, sem_weighted, failed_credits))
        print(f"[OK] Semester {i+1} GPA: {gpa:.2f} | Total Credits: {sem_credits:.1f} | Failed Credits: {failed_credits:.1f}")

    # calculate original CGPA ignoring failed courses
    total_credits = sum(s[0] for s in semester_data)
    total_weighted = sum(s[1] for s in semester_data)
    total_failed = sum(s[2] for s in semester_data)
    original_cgpa = total_weighted / total_credits if total_credits > 0 else 0

    print("\n==============================")
    print(f"Original CGPA: {original_cgpa:.2f}")
    print(f"Total Failed Credits: {total_failed:.1f}")
    print("==============================")

    if total_failed <= 0:
        print("No failed grades detected. 🎉")
        return

    print("\nIf failed courses are cleared as:\n")
    print("| Grade | CGPA After Clearing |")
    print("|-------|--------------------|")
    for grade in ['S', 'A', 'B', 'C', 'D', 'E']:
        new_weighted = total_weighted + total_failed * grade_points[grade]
        new_total_credits = total_credits + total_failed
        new_cgpa = new_weighted / new_total_credits
        print(f"| {grade} ({grade_points[grade]}) | {new_cgpa:.2f} |")

if __name__ == "__main__":
    main()
