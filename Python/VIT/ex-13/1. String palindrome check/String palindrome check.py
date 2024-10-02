word=str(input("Enter a string: "))
wordR=word[::-1]
if word==wordR:
    print("Palindrome")
else:
    print("Not a palindrome")
