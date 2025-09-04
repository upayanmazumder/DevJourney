import java.util.*;

class FrequencySorter {
    void sortByFrequency(int[] arr) {
        int n = arr.length;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : arr)
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        Integer[] boxed = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Arrays.sort(boxed, (a, b) -> {
            int fa = freq.get(a), fb = freq.get(b);
            if (fa != fb)
                return fb - fa;
            return a - b;
        });
        for (int x : boxed)
            System.out.print(x + " ");
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        FrequencySorter fs = new FrequencySorter();
        fs.sortByFrequency(arr);
    }
}
