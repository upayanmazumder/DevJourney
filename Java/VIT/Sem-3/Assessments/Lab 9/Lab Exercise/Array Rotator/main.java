class ArrayRotator {
    private int[] arr;
    private int rotateBy;

    public ArrayRotator(int[] arr, int rotateBy) {
        this.arr = arr;
        this.rotateBy = rotateBy;
    }

    public void printRotatedArray() {
        int n = arr.length;
        int[] rotated = new int[n];
        for (int i = 0; i < n; i++) {
            rotated[(i + rotateBy) % n] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            System.out.print(rotated[i]);
            if (i < n - 1) {
                System.out.print(" ");
            }
        }
    }
}
