import analyzer as a

n = int(input("Enter number of elements: "))
l = []

for i in range(n):
    element = input(f"Enter element {i+1}: ")
    try:
        element = eval(element)
        l.append(element)
    except:
        l.append(element)

print(l)

print("""
    a. Count the total elements in the list
    b. Count the total integers, float and string elements in the list
    c. Extract only the unique elements from the list
    d. Extract only the duplicate elements from the list  
""")

choice = input("Enter your choice: ")
if choice == 'a':
    print("Total elements in list:", a.count_elements(l))
elif choice == 'b':
    res = a.count_elements_by_type(l)
    print(f"The list has {res[0]} integers, {res[1]} floats and {res[2]} strings")
elif choice == 'c':
    print("Unique elements in list:", a.extract_uniques(l))
elif choice == 'd':
    print("Duplicate elements in list:", a.extract_duplicates(l))
else:
    print("Invalid choice")