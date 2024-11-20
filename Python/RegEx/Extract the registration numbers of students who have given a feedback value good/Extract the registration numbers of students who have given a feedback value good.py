import re

s = """
1.24BCE5002 - University is average.
2.24BAI5567 - University is excellent.
3.23BKT3356 - University is good.
4.23BCI6678 - University is bad.
5.22BCT7890 - University is good.
6.24BKT6666 - University is good.
"""

goodPat = r'(\d{2}[A-Z]{3}\d{4}) - University is good'
good = re.findall(goodPat, s)
print(good)