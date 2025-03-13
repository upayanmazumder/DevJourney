Single File Programming Question
Problem Statement



You are a sales representative at an electronics store. A customer is interested in purchasing a new television and refrigerator. You can input and display information about the devices and calculate the following relevant metrics:



Class Descriptions:



Device Class:

Contains brand and price as attributes.
Provides a display method to show device brand and price.


Television Class (Inherits from Device):

Inherits attributes brand and price from the Device class.
Has an additional attribute screenSize to store the screen size.
Contains a calculatePixelDensity method to calculate the pixel density.


Refrigerator Class (Inherits from Device):

Inherits attributes brand and price from the Device class.
Includes an extra attribute capacity to represent the storage capacity.
Provides the calculateEnergyEfficiency method to calculate the energy efficiency.


Formulas used:



For Television:

Screen size in cm = screen size in inches * 2.54

Pixel Density = (resolution width * resolution height) / (screen size in cm * screen size in cm)



For Refrigerator:

Capacity in Cubic Feet = capacity in liters * 0.0353

Energy Efficiency = Energy consumption in KWh / capacity cubic feet

Input format :
The first line consists of a string representing the TV brand, a double value representing the TV price, and an integer representing the TV screen size (in inches) separated by a space.

The second line consists of a string representing the Refridgerator brand, a double value representing the Refridgerator price, and an integer representing the Refridgerator capacity separated by a space.

The third line consists of an integer representing the TV Resolution Width (in cm) and an integer representing TV Resolution Height (in cm) separated by a space.

The fourth line consists of a double value representing the refrigerator's energy consumption.

Output format :
The first line prints "Television Information:".

The following three line prints the Television Information as follows:



"Device: [Brand], Price: $[Price]" where [Brand] is a string and [Price] is a double, displayed with two decimal places, representing the brand and price of the television.
"Screen Size: [Screen Size] inches ([Screen Size in CM] cm)" where [Screen Size] is an integer, representing the screen size in inches, and [Screen Size in CM] is a double displayed with one decimal place, representing the screen size in centimeters.
"Pixel Density: [Pixel Density] pixels per square centimeter" where [Pixel Density] is a double, displayed with one decimal place, representing the pixel density.


After a new line, the next line prints "Refrigerator Information:".

The following three line prints the Refrigerator Information as follows:



"Device: [Brand], Price: $[Price]" where [Brand] is a string and [Price] is a double, displayed with one decimal place, representing the brand and price of the refrigerator.
"Capacity: [Capacity in Liters] liters ([Capacity in Cubic Feet] cubic feet)" where [Capacity in Liters] is an integer, representing the capacity in liters, and [Capacity in Cubic Feet] is a double displayed with one decimal place, representing the capacity in cubic feet.
"Energy Efficiency: [Energy Efficiency] kWh per cubic foot" where [Energy Efficiency] is a double displayed with one decimal place, representing the energy efficiency in kWh per cubic foot.


Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

For Television:

0.01 <= Price <= 10,000.00

1 <= Screen Size <= 100

1 <= Resolution Width <= 8000

1 <= Resolution Height <= 8000



For Refrigerator:

0.01 <= Price <= 10,000.00

1 <= Capacity <= 5000

0.01 <= Energy Consumption <= 5000.00

Sample test cases :
Input 1 :
Samsung 699.99 43
LG 899.99 350
1920 1080
450
Output 1 :
Television Information:
Device: Samsung, Price: $699.99
Screen Size: 43 inches (109.2 cm)
Pixel Density: 173.8 pixels per square centimeter

Refrigerator Information:
Device: LG, Price: $900.0
Capacity: 350 liters (12.4 cubic feet)
Energy Efficiency: 36.4 kWh per cubic foot
Input 2 :
Sony 499.99 32
Whirlpool 749.99 400
1366 768
600
Output 2 :
Television Information:
Device: Sony, Price: $499.99
Screen Size: 32 inches (81.3 cm)
Pixel Density: 158.8 pixels per square centimeter

Refrigerator Information:
Device: Whirlpool, Price: $750.0
Capacity: 400 liters (14.1 cubic feet)
Energy Efficiency: 42.5 kWh per cubic foot