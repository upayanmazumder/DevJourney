Single File Programming Question
Problem Statement

John is organizing a fruit festival, and the quantities of various fruits are stored in a HashMap where fruit names are keys and quantities are values.

Help him develop a program to find the total quantity of fruits for the festival by summing up the values in the HashMap.

Input format :
The input consists of fruit quantities in the format 'fruitName:quantity', where fruitName is the name of the fruit(a string), and quantity is a double value representing the quantity.

The input is terminated by entering "done".

Output format :
The output prints a double value, representing the sum of values in the HashMap, rounded off to two decimal places.

If the value is not numeric, print "Invalid input".

If any special characters other than ':' are entered, print "Invalid format".

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ Length of the String ≤ 20

1.0 ≤ quantity ≤ 100.0

Sample test cases :
Input 1 :
Banana:15.2
Orange:56.3
Mango:47.3
done
Output 1 :
118.80
Input 2 :
Papaya:25.8
Muskmelon:34.9
Grapes:98.1
Cherry:34.7
done
Output 2 :
193.50
Input 3 :
Banana:w
Strawberry:s
done
Output 3 :
Invalid input
Input 4 :
Guava-12.6
Kiwi-96.2
Blueberry-85.1
done
Output 4 :
Invalid format
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
123
import java.util.Scanner;import java.util.Map;import java.util.HashMap;
Whitelist
Set 1:
HashMap
Fill your code here
Java (11)
theme
instruction
1234
// You are using Javaclass ValueProcessor { //type your code here}
Footer Snippet
12345678910
class Main { public static void main(String[] args) { Scanner scanner = new Scanner(System.in); Map<String, Double> valueMap = ValueProcessor.readValues(scanner); if (valueMap != null) { double sum = ValueProcessor.calculateSum(valueMap); System.out.printf("%.2f\n", sum); } scanner.close(); }
Provide Custom Input
