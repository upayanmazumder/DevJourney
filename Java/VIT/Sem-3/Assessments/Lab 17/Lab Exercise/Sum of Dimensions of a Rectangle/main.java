import java.util.Scanner;

class Area<T extends Number> {
    private T length;
    private T width;

    public Area(T length, T width) {
        this.length = length;
        this.width = width;
    }

    public long calculateSum() {
        return length.longValue() + width.longValue();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int length = scanner.nextInt();
        int width = scanner.nextInt();

        scanner.close();

        Area<Integer> rectangleArea = new Area<>(length, width);

        System.out.println(rectangleArea.calculateSum());
    }
}