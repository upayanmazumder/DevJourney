Single File Programming Question
Problem Statement



Enigma is tasked with developing a comprehensive retail management system for a multi-product store. The system needs to handle diverse products such as electronics and clothing, each with specific costs, prices, and additional costs like warranty or material expenses. 



Create an abstract class Product with abstract methods calculateTotalCost() and calculateProfitMargin(). Subclasses ElectronicsProduct and ClothingProduct, implement these abstract methods to cater to the specific needs of each product type.



Formula

Total cost of electronic product = cost + warranty cost

Total cost of clothing product = cost + material cost

Profit margin = ((price - cost) / price) * 100.

Input format :
The first line of input consists of three positive double values, representing the cost, price, and warranty cost of the electronic product, separated by space.

The second line consists of three positive double values, representing the cost, price, and material cost of the clothing product, separated by space.

Output format :
The first line of output prints "Electronics Product:".

The second line prints "Total Cost: " followed by a double representing the total cost of the electronics product, formatted to two decimal places.

The third line prints "Profit Margin: " followed by a double representing the profit margin of the electronics product, formatted to two decimal places.

After a blank line, the output prints "Clothing Product:".

The next line prints "Total Cost: " followed by a double representing the total cost of the clothing product, formatted to two decimal places.

The final line prints "Profit Margin: " followed by a double representing the profit margin of the clothing product, formatted to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ cost ≤ 1600.0

1.0 ≤ price ≤ 1600.0

1.0 ≤ warranty, material cost ≤ 160.0

Sample test cases :
Input 1 :
500.7 799.7 50.6
30.4 89.9 15.2
Output 1 :
Electronics Product:
Total Cost: 551.30
Profit Margin: 37.39

Clothing Product:
Total Cost: 45.60
Profit Margin: 66.18
Input 2 :
100.1 199.9 10.7
25.2 59.9 78.5
Output 2 :
Electronics Product:
Total Cost: 110.80
Profit Margin: 49.92

Clothing Product:
Total Cost: 103.70
Profit Margin: 57.93
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0