import java.util.Scanner;

interface NumberProvider<T extends Number> {
    T getNumber(int index);

    int getSize();
}

class WorkoutData implements NumberProvider<Integer> {
    private Integer[] calories;

    public WorkoutData(Integer[] calories) {
        this.calories = calories;
    }

    @Override
    public Integer getNumber(int index) {
        return calories[index];
    }

    @Override
    public int getSize() {
        return calories.length;
    }
}

class Main {

    public static <T extends Number> long calculateSum(NumberProvider<T> provider) {
        long totalSum = 0;
        for (int i = 0; i < provider.getSize(); i++) {
            totalSum += provider.getNumber(i).longValue();
        }
        return totalSum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        Integer[] calories = new Integer[N];

        for (int i = 0; i < N; i++) {
            calories[i] = scanner.nextInt();
        }

        scanner.close();

        WorkoutData data = new WorkoutData(calories);

        long totalCaloriesBurned = calculateSum(data);

        System.out.println(totalCaloriesBurned);
    }
}