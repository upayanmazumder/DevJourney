amount=int(input("Enter amount: Rs."))
notesDenom=[500,200,100,50,20,10,5,2,1]
notesCount=[0,0,0,0,0,0,0,0,0]
denom=0
while notesDenom: #While more amount is left
    if  amount>=notesDenom[denom]:  #If the amount is greater than the current denomination
        notesCount[denom]=amount//notesDenom[denom] #Calculate number of current denomination notes
        amount=amount%notesDenom[denom] #Update the amount
    denom+=1    #Move to the next denomination
    if denom==9:    #If all denominations have been checked
        break
print("Denomination breakdown:")
for i in range(9):
    if notesCount[i]>0: #Display the denomination and its count only if it is used
        print(f"Rs. {notesDenom[i]}: {notesCount[i]} note(s)")