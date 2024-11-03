text = str(input("Enter a string: "))

chars = list(text)

textR = []

for i in range(len(chars)):
    textR.insert(0, chars[i])
    
for char in textR:
    print(char, end='')
