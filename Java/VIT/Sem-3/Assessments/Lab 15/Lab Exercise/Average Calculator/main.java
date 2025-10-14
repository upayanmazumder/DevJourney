import java.io.*;

class AverageCalculator {

    public double calculateAverage(int[] numbers) {
        int sum = 0;
        for (int num : numbers)
            sum += num;
        return sum / 3.0;
    }

    public void writeAverageToFile(double average, String filename) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
        bw.write(String.format("%.2f", average));
        bw.close();
    }

    public void displayResult(double average) {
        if (((int) average) % 2 == 0)
            System.out.printf("%.2f", average * average);
        else
            System.out.printf("%.2f", average * average * average);
    }

    public void writeInputToFile(String input, String filename) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
        bw.write(input);
        bw.close();
    }
}