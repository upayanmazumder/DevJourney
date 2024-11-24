def to_lowercase(s):
    res = ''
    for i in range(len(s)):
        a = ord(s[i])
        if a >= 65 and a <=90:
            a += 32
        res += chr(a)
    return res
