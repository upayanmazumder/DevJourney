import re

with open("file.txt", "r") as content:

    Vowels = 0
    Consonants = 0

    for line in content:
        vCount = len(re.findall(r'[aeiouAEIOU]',line))
        cCount = len(re.findall(r'[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]',line))
        Vowels += vCount
        Consonants += cCount

with open("file.txt",'a') as content:
    res = f"\nVowels => {Vowels}\nConsonants => {Consonants}"
    content.write(res)
