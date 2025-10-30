import java.util.ArrayList;
import java.util.Scanner;

class NumberProcessor {
    private ArrayList<Integer> numList;
    
    public NumberProcessor(ArrayList<Integer> numList) {
        this.numList = numList;
    }
    
    public void processNumbers() {
        ArrayList<Integer> temp = new ArrayList<>();
        for (int i = 0; i < numList.size(); i++) {
            int num = numList.get(i);
            if (temp.isEmpty() || num > temp.get(temp.size() - 1)) {
                temp.add(num);
            }
        }
        numList.clear();
        for (int num : temp) {
            numList.add(num);
        }
        displayList();
    }
    
    public void displayList() {
        System.out.println(numList);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number_of_elements = input.nextInt();
        if (number_of_elements <= 0) {
            return;
        }
        ArrayList<Integer> numList = new ArrayList<>();
        for (int ctr = 0; ctr < number_of_elements; ctr++) {
            numList.add(input.nextInt());
        }
        NumberProcessor processor = new NumberProcessor(numList);
        processor.processNumbers();
    }
}