import java.util.*;

class TransactionProcessor {
    public static void processTransactions(int n, Scanner sc) {

        ArrayList<Integer> uniqueTransactions = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int currentAmount = sc.nextInt();

            if (!uniqueTransactions.contains(currentAmount)) {

                uniqueTransactions.add(currentAmount);
            }
        }

        for (int amount : uniqueTransactions) {
            System.out.println(amount);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TransactionProcessor.processTransactions(n, sc);
        sc.close();
    }
}