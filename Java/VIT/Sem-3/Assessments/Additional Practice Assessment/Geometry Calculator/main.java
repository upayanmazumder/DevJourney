import java.util.*;

abstract class Shape {
    abstract void rectangleArea(int length, int breadth);
    abstract void squareArea(int side);
    abstract void circleArea(int radius);
}

class Area extends Shape {
    void rectangleArea(int length, int breadth) {
        int area = length * breadth;
        System.out.println(area);
    }

    void squareArea(int side) {
        int area = side * side;
        System.out.println(area);
    }

    void circleArea(int radius) {
        double area = Math.PI * radius * radius;
        System.out.printf("%.2f", area);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();
        int breadth = sc.nextInt();
        int side = sc.nextInt();
        int radius = sc.nextInt();

        Area a = new Area();
        a.rectangleArea(length, breadth);
        a.squareArea(side);
        a.circleArea(radius);
    }
}
