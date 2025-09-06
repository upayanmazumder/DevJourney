Single File Programming Question
Problem Statement:
Ram is working on a Java program to calculate the Euclidean distance between two points in a 2D plane. He needs to design a class called "DistanceBetweenPoints" that takes the coordinates of two points as input and calculates the straight-line distance between them.
Additionally, the class should make use of a constructor to initialize the coordinates and perform the distance calculation.
Formula :
￼
Input format :
The first line contains an integer x1, representing the x-coordinate of the first point.
The second line contains an integer y1, representing the y-coordinate of the first point.
The third line contains an integer x2, representing the x-coordinate of the second point.
The fourth line contains an integer y2, representing the y-coordinate of the second point.
Output format :
The output prints a double value representing the distance between the two points, rounded to two decimal places.
Refer to the sample output for formatting specifications.
Code constraints :
The given test cases fall under the following constraints:
-1000 ≤ x1, y1, x2, y2 ≤ 1000
Sample test cases :
Input 1 :
0 0 3 4
Output 1 :
5.00
Input 2 :
1 2 4 6
Output 2 :
5.00
Input 3 :
-2 -3 3 1
Output 3 :
6.40
Footer Snippet
12345678910
class Main {    public static void main(String[] args) {        Scanner scanner = new Scanner(System.in);        int x1 = scanner.nextInt();        int y1 = scanner.nextInt();        int x2 = scanner.nextInt();        int y2 = scanner.nextInt();                DistanceBetweenPoints calculator = new DistanceBetweenPoints(x1, y1, x2, y2);
Provide Custom Input
