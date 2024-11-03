d={}
dMini={}

for i in range(15):
    dMini.clear
    j=i+1
    dMini.setdefault(j,j**2)
    d.update(dMini)
    
print(d)