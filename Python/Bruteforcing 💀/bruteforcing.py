import re

def brute_force(password):
    characters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'
    attempts = 0

    def generate_attempts(current_attempt):
        nonlocal attempts
        if len(current_attempt) > len(password):
            return None
        attempts += 1
        print(f"Attempt {attempts}: {current_attempt}")
        if current_attempt == password:
            return current_attempt, attempts
        for char in characters:
            result = generate_attempts(current_attempt + char)
            if result:
                return result
        return None

    return generate_attempts('')

password = input("Enter the password: ")
rePat = r'[a-zA-Z0-9]+'
if re.fullmatch(rePat, password):
    print("Password is valid")
    cPassword, attempts = brute_force(password)
    if cPassword:
        print(f"Password cracked: {cPassword} in {attempts} attempts")
    else:
        print(f"Failed to crack the password after {attempts} attempts")

else:
    print("Password is invalid")