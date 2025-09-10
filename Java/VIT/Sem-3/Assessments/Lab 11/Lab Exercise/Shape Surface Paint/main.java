class Shape {
    protected String shapeType;
    protected double radius;

    public void setShape(String type, Scanner scanner) {
        this.shapeType = type;
        if ("Sphere".equals(type)) {
            this.radius = scanner.nextDouble();
        }
    }
}

class Area extends Shape {
    protected double area;

    public void calculateArea() {
        if ("Sphere".equals(shapeType)) {
            area = 4 * 3.14 * radius * radius;
            System.out.printf("Area of Sphere is: %.2f\n", area);
        } else {
            System.out.println("Invalid type");
        }
    }
}

class Cost extends Area {
    private double costPerSqMeter;
    private double totalCost;

    public void setCost(double cost) {
        this.costPerSqMeter = cost;
    }

    public void calculateCost() {
        if ("Sphere".equals(shapeType)) {
            totalCost = area * costPerSqMeter;
            System.out.printf("Cost to paint the shape is: %.2f\n", totalCost);

        }
    }
}