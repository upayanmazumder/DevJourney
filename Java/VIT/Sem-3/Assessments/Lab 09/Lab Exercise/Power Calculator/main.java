class PowerCalculator {
    double base;
    int exponent;

    PowerCalculator(double base, int exponent) {
        this.base = base;
        this.exponent = exponent;
    }

    void displayResult() {
        if (base == 0.0 && exponent < 0) {
            System.out.println("Result is undefined. Base is zero, and the exponent is negative");
        } else {
            double result = Math.pow(base, exponent);
            System.out.println(base + " raised to the power of " + exponent + " is " + result);
        }
    }
}