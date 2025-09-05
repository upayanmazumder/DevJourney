class FibonacciCalculator {
    // Method to calculate nth Fibonacci number (returns int to match footer)
    public static int calculateFibonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    // Method to check even/odd and digit sum in required format
    public static String checkEvenOddAndSumDigits(int num) {
        String parity = (num % 2 == 0) ? "Even" : "Odd";
        int sum = 0;
        int temp = num;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return parity + ", Digit Sum: " + sum;
    }
}
