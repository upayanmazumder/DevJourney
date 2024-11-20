import re

string = """
List of Mail-id:
1.Ramesh, ramesh@gmail.com, ramesh@vit.ac.in
2.Suresh, suresh123456@yahoo.in, suresh@vitstudent.ac.in
3.Babu, babucool1234@gmail.com, babu@vitstudent.ac.in
4.Bala, bala_2222@reddit.in
5.Ram, ram_phd@gmail.com, ram@vit.ac.in
"""

linesPat = r'[a-z0-9]+@vit.ac.in'
lines = re.findall(linesPat,string)

print(lines)