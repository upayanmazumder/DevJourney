l = eval(input(""))
mid = l[len(l) // 2]

def check_max(l):
    """ Check max 2 str, 2 complex and 2 int """
    sCount = 0
    cCount = 0
    iCount = 0

    for i in l:
        t = type(i)
        if t == str:
            sCount += 1
        elif t == complex:
            cCount += 1
        elif t == int:
            iCount += 1
        
    if sCount < 3 and cCount < 3 and iCount < 3:
        return True
    else:
        return False
    
def is_prime(n):
    """Checks whether the number is prime or not"""

    for i in range(2, n):
        if n % i == 0:
            return False
    
    return True

def check_at_least_one_integer_is_prime(l):
    """Check if the integer is prime in the given list"""

    for integer in l:
        if type(integer) == int and integer > 0:
            if is_prime(integer):
                return True

    return False
    
def reverse_string(s):
    """Reverses the string"""
    return s[::-1]

def interchange_complex_part(x):
    """Interchanges the real and imaginary part of the complex number"""
    r = x.real
    c = x.imag
    r,c = c,r
    res = complex(r,c)

    return res

def is_palindrome(x):
    """Checks if the item is a palindrome"""
    sOrg = x.lower()
    sRev = sOrg[::-1]

    if sOrg == sRev:
        return True
    else:
        return False
    
def is_at_least_one_palindrome(l):
    """Checks if the list has at least one palindrome"""

    for i in range(len(l)):
        if type(l[i]) == str and is_palindrome(l[i]):
            return True

    return False

# Main function
sat = 0

if len(l) > 6:
    print("Invalid Data!")
else:
    # Check 1
    if check_max(l):
        # Check 2
        if check_at_least_one_integer_is_prime(l):
            sat += 1
            for i in range(len(l)):
                if type(l[i]) == str:
                    l[i] = reverse_string(l[i])
                elif type(l[i]) == complex:
                    l[i] = interchange_complex_part(l[i])
        # Check 3
        if is_at_least_one_palindrome(l):
            sat += 1
            # Conjugate the complex numbers and negate the integers
            for i in range(len(l)):
                if type(l[i]) == complex:
                    l[i] = l[i].conjugate()
                elif type(l[i]) == int:
                    l[i] = -l[i]

        # Check 4
        if sat == 2:
            print(mid)

        # Check 5
        elif sat == 0:
            for i in range(len(l)):
                if type(l[i]) == str:
                    charList = list(l[i])  # Convert string to list of characters
                    l.pop(i)              # Remove the original string
                    for char in reversed(charList):  # Insert characters in reverse
                        l.insert(i, char)
    
        if sat != 2:    
            print(l)
    else:
        print("Invalid Data!")
