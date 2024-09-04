n=int(input("Enter no. of subjects: "))
sum=0
marks=[]
i=0

for i in range(0,n,1):
    marks[i]=int(input("Enter marks of subject "+str(i+1)+": "))
    sum=sum+marks[i]
    i+=1

avg = sum / n
print("Average marks: ",avg)