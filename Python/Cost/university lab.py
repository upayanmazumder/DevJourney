nCo=int(input("Enter number of computers: "))
nT=int(input("Enter number of tables: "))
nCh=int(input("Enter number of chairs: "))
nL=float(input("Enter hours of work: "))

rCo=float(input("Enter cost of each computer: "))
rT=float(input("Enter cost of each table: "))
rCh=float(input("Enter cost of each chair: "))
rL=float(input("Enter wage per hour: "))

cCo=rCo*nCo #Total computer cost
cT=rT*nT #Total table cost
cCh=rCh*nCh #Total chair cost
cFu=cT+cCh #Total Furniture cost
cL=nL*rL #Total labour cost
cTot=cCo+cT+cCh+cFu+cL

print(f"Total expenses: {cTot}")
print(f"Expenses breakdown: \n\tComputers: {cCo}\n\tFurniture: {cFu}\n\t\tTables: {cT}\n\t\tChairs: {cCh}\n\tLabour: {cL}")

