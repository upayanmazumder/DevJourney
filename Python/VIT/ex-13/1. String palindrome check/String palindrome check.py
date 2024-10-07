text=str(input("Enter a string: "))
textF=text.lower()
textR=textF[::-1]
if textF==textR:
    print("Palindrome")
else:
    print("Not a palindrome")
