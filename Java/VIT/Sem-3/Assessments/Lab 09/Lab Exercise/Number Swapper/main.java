class NumberSwapper {
    private int num1;
    private int num2;

    // Constructor
    public NumberSwapper(int num1, int num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    // Swap method
    public void swapNumbers() {
        if (num1 == num2) {
            System.out.println("Numbers are identical and need not be swapped");
        } else {
            int temp = num1;
            num1 = num2;
            num2 = temp;
            System.out.println("Numbers after swapping: Number1=" + num1 + ", Number2=" + num2);
        }
    }
}