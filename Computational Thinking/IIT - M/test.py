import json

# Step 1: Load the JSON data (Pile 1)
with open('D:/upayanmazumder/DevJourney/Computational Thinking/IIT - M/scores.json', 'r') as file:
    pile1 = json.load(file)

# Step 2: Initialize variables A, B, C, D, Y, and X
A, B, C, D = 0, 0, 0, 0
Y = 100
X = None

# Step 10: Create Pile 2 to move cards
pile2 = []

# Step 4: Iterate over Pile 1 until it's empty
while pile1:
    # Step 5: Read the top card in Pile 1
    top_card = pile1.pop(0)  # Remove the top card from Pile 1

    # Step 6-9: Check the City/Town and update the respective variable and check against Y
    if top_card['CityTown'] == "Chennai":
        A += 1
        if A < Y:
            Y = A
            X = "Chennai"
    elif top_card['CityTown'] == "Bengaluru":
        B += 1
        if B < Y:
            Y = B
            X = "Bengaluru"
    elif top_card['CityTown'] == "Madurai":
        C += 1
        if C < Y:
            Y = C
            X = "Madurai"
    elif top_card['CityTown'] == "Vellore":
        D += 1
        if D < Y:
            Y = D
            X = "Vellore"

    # Step 10: Move the current card to Pile 2
    pile2.append(top_card)

# Output the result
print(f"The city/town with the minimum count is: {X}, with a count of {Y}")
