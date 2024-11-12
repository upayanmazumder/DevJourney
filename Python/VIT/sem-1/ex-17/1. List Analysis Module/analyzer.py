def count_elements(l):
    return len(l)

def count_elements_by_type(l):
    count = [0] * 3
    for element in l:
        if type(element) == int:
            count[0] += 1
        elif type(element) == float:
            count[1] += 1
        elif type(element) == str:
            count[2] += 1
    return count

def extract_uniques(l):
    unique = []
    for i in range(len(l)): # Check for each element
        found = False # Flag to check if element is unique
        for j in range(len(l)):
            if l[i] == l[j] and i != j:
                found = True # Element is not unique
        if not found:
            unique.append(l[i])
    return unique

def extract_duplicates(l):
    duplicates = []
    uniques = extract_uniques(l)
    for element in l:
        if element not in uniques:
            duplicates.append(element)
    return duplicates