# E-Learning Administrator

## Single File Programming Question

## Problem Statement

Tony is an e-learning platform administrator, he oversees the user ratings for various online courses offered in the platform.

To enhance user experience, you should assist him in utilizing a HashMap to store course ratings given by learners. Regularly, he analyzes this data to identify the highest and lowest-rated courses, enabling targeted improvements and ensuring the quality of the educational content. This process assists in maintaining a competitive and engaging online learning environment for the users.
#### Input:

```
format :
```

The input consists of a string representing the course name, followed by a double value representing the course's rating, in separate lines.
The input is terminated by entering "done".
#### Output:

```
format :
```

The first line of output prints the string "Highest Rated Course: " followed by the highest-rated course.
The second line prints the string "Lowest Rated Course: " followed by the lowest-rated courses.

Refer to the sample output for formatting specifications.
Code constraints :
The given test cases fall under the following constraints:
1 ≤ Length of the String ≤ 25
0.0 ≤ rating ≤ 5.0
Sample test cases :
#### Input 1:

```
DSA
4.0
OOPS
4.2
C
3.2
done
```

#### Output 1:

```
Highest Rated Course: OOPS
Lowest Rated Course: C
```

#### Input 2:

```
Accounting & Finance
3.7
Art & Design
4.2
Architecture
3.9
done
```

#### Output 2:

```
Highest Rated Course: Art & Design
Lowest Rated Course: Accounting & Finance
```

Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
Header Snippet
1
2
3
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
Fill your code here
Java (17)
1
2
3
4
// You are using Java-17version
class CourseAnalyzer {
//type your code here
}
Footer Snippet
1
2
3
4
5
6
7
8
9
10
public class Main {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
Map<String, Double> courseRatings = new HashMap<>();
while (true) {
String courseName = scanner.nextLine();
if (courseName.equalsIgnoreCase("done")) {
break;

Provide Custom Input
