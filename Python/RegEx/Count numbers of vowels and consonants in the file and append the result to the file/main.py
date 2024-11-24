import re

with open("file.txt", "r") as content:

    Vowels = 0
    Consonants = 0

    for line in content:
        print(line, end='')
        vCount = len(re.findall(r'[aeiouAEIOU]',line))
        cCount = len(re.findall(r'[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]',line))
        Vowels += vCount
        Consonants += cCount

with open("file.txt",'w') as content:
    res = f"Vowels => {Vowels}\nConsonants => {Consonants}"
    content.write(res)
