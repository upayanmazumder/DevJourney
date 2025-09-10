import java.math.BigInteger;

class Factorial {
    // Method to calculate factorial using BigInteger
    public BigInteger calculateFactorial(int n) {
        BigInteger result = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }

    // Method to calculate sum of digits of a BigInteger
    public int calculateDigitSum(BigInteger num) {
        String s = num.toString();
        int sum = 0;
        for (char c : s.toCharArray()) {
            sum += c - '0';
        }
        return sum;
    }
}
