class ArrayConcatenator {
    private int[] concatenatedArray;

    public ArrayConcatenator(int[] arr1, int[] arr2) {
        concatenatedArray = new int[arr1.length + arr2.length];
        int index = 0;

        for (int i = 0; i < arr1.length; i++) {
            concatenatedArray[index++] = arr1[i];
        }
        for (int i = 0; i < arr2.length; i++) {
            concatenatedArray[index++] = arr2[i];
        }
    }

    public void printConcatenatedArray() {
        for (int num : concatenatedArray) {
            System.out.print(num + " ");
        }
    }
}