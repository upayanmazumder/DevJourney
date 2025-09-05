class NumberClassifier {
    private int[] arr;
    private int[] even;
    private int[] odd;
    private int evenCount = 0;
    private int oddCount = 0;

    public void initializeArrays(int size) {
        even = new int[size];
        odd = new int[size];
    }

    public void setInputValues(int[] arr) {
        this.arr = arr;
    }

    public void classifyNumbers() {
        for (int num : arr) {
            if (num % 2 == 0) {
                even[evenCount++] = num;
            } else {
                odd[oddCount++] = num;
            }
        }
    }

    public void printEvenNumbers() {
        System.out.print("Even numbers: ");
        for (int i = 0; i < evenCount; i++) {
            System.out.print(even[i] + " ");
        }
        System.out.println();
    }

    public void printOddNumbers() {
        System.out.print("Odd numbers: ");
        for (int i = 0; i < oddCount; i++) {
            System.out.print(odd[i] + " ");
        }
        System.out.println();
    }
}