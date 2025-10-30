import java.util.Scanner;

class FizzBuzz<T extends Number> {
    private T endRange;

    public FizzBuzz(T endRange) {
        this.endRange = endRange;
    }

    public void printSequence() {
        int N = endRange.intValue();
        for (int i = 1; i <= N; i++) {
            boolean divisibleBy3 = (i % 3 == 0);
            boolean divisibleBy5 = (i % 5 == 0);

            if (divisibleBy3 && divisibleBy5) {
                System.out.println("FizzBuzz");
            } else if (divisibleBy3) {
                System.out.println("Fizz");
            } else if (divisibleBy5) {
                System.out.println("Buzz");
            } else {
                System.out.println(i);
            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        scanner.close();

        FizzBuzz<Integer> program = new FizzBuzz<>(N);
        program.printSequence();
    }
}