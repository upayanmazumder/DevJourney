# Single File Programming Question

## Problem Statement

AV's Construction Company specializes in building residential and commercial properties. They are currently working on multiple construction projects simultaneously, and each project requires different construction materials.
To manage the inventory efficiently, the company needs a system to keep track of the available construction materials and their quantities. They want to implement a program with functions to add new materials, update material quantities, and display the current inventory status.
Help them write a program for the same using function templates.

### Input format :

The first line consists of an integer 'n' representing the number of materials to add to the inventory.
In the next 'n' lines, each line consists of a string 'name' and an integer 'quantity', separated by a space, representing the name and quantity of material to add to the inventory.
The last line consists of a string 'name' and an integer 'quantity', separated by a space, representing the name and updated quantity of a material in the inventory.

### Output format :

The program displays the messages as it adds materials to the inventory, updates the quantity of existing material, and displays the current inventory status.
The output displays the name and quantity of each material in the current inventory status.
Refer to the sample output for the formatting specifications.

### Code constraints :

1 \<= n \<= 10

### Sample test cases :

#### Input 1 :

3 Cement 100 Bricks 500 SteelBars 200 Cement 50

#### Output 1 :

Added 100 units of Cement to the inventory. Added 500 units of Bricks to the inventory. Added 200 units of SteelBars to the inventory. Updated Cement quantity to 50 units in the inventory. Current Inventory Status: Cement: 50 units Bricks: 500 units SteelBars: 200 units

#### Input 2 :

3 Cement 100 Bricks 500 SteelBars 200 Steel 50

#### Output 2 :

Added 100 units of Cement to the inventory. Added 500 units of Bricks to the inventory. Added 200 units of SteelBars to the inventory. Material Steel not found in the inventory. Current Inventory Status: Cement: 100 units Bricks: 500 units SteelBars: 200 units
