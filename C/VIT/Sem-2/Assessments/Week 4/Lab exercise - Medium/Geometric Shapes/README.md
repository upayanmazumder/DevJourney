# Single File Programming Question

## Problem Statement

Ashok, an aspiring architect, needs a program to calculate volumes of geometric shapes.

He wants to define structures Point3D, Sphere, Cylinder, and GeometryCalculator. Help him accept input for the details of the sphere and cylinder. Display their volumes with two decimal places.

Structure Details:

Point3D: Represents a point in 3D space with coordinates (x, y, z).

Sphere: Describes a sphere with a centre of type Point3D and a radius.

Cylinder: Defines a cylinder with a base centre (Point3D), radius, and height.

GeometryCalculator: Combines a Sphere and a Cylinder for calculations.

Formulae:

Sphere Volume = (4/3) x 3.14 x r3

Cylinder Volume = 3.14 x R2 x h

### Input format :

The first line of input consists of three space-separated double values x, y, and z, representing the sphere center.

The second line consists of a double value r, representing the sphere Radius.

The third line consists of three space-separated double values X, Y, and Z, representing the cylinder base center.

The fourth line consists of two space-separated double values R, H, representing the cylinder radius and cylinder height.

### Output format :

The first line prints a double value in the following format: "Sphere's Volume: [Volume rounded to two decimal places] cubic units".

The second line prints a double value in the following format: "Cylinder's Volume: [Volume rounded to two decimal places] cubic units".

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1.0 ≤ x, y, z, r ≤ 100.0

1.0 ≤ X, Y, Z, R, H ≤ 100.0

### Sample test cases :

#### Input 1 :

12.1 18.7 21.8
7.1
18.1 15.5 13.4
41.1 13.2

#### Output 1 :

Sphere's Volume: 1498.45 cubic units
Cylinder's Volume: 70014.38 cubic units

#### Input 2 :

1.2 3.4 5.6
1.5
1.6 2.4 5.6
3.2 6.7

#### Output 2 :

Sphere's Volume: 14.13 cubic units
Cylinder's Volume: 215.43 cubic units
Whitelist
Set 1:
struct Point3D
struct Sphere
struct Cylinder
struct GeometryCalculator
