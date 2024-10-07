word=str(input("Enter a string: "))
wordF=word.lower()
wordR=wordF[::-1]
if wordF==wordR:
    print("Palindrome")
else:
    print("Not a palindrome")
