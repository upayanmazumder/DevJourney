import java.util.Scanner;

interface ExpenseRecorder {
    void recordExpense(double expense);
}

interface BudgetCalculator {
    double calculateRemainingBudget();
}

class ExpenseTracker implements ExpenseRecorder, BudgetCalculator {
    private double initialBudget;
    private double totalExpenses;

    public ExpenseTracker(double initialBudget) {
        this.initialBudget = initialBudget;
        this.totalExpenses = 0.0;
    }

    @Override
    public void recordExpense(double expense) {
        totalExpenses += expense;
    }

    @Override
    public double calculateRemainingBudget() {
        return initialBudget - totalExpenses;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double budget = scanner.nextDouble();
        ExpenseTracker tracker = new ExpenseTracker(budget);

        while (true) {
            double expense = scanner.nextDouble();
            if (expense == 0.0)
                break;
            tracker.recordExpense(expense);
        }

        double remainingBudget = tracker.calculateRemainingBudget();
        if (remainingBudget >= 0) {
            System.out.printf("Remaining budget: Rs. %.2f", remainingBudget);
        } else {
            System.out.println("No remaining budget, You've exceeded your budget!");
        }

        scanner.close();
    }
}