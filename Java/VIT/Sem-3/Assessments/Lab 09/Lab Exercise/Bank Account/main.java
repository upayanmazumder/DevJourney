class BankAccount {
    private double balance;
    private String accountType;

    public BankAccount(double balance, String accountType) {
        this.balance = balance;
        this.accountType = accountType;
    }

    public double calculateYearlyInterest() {
        double rate;
        switch (accountType) {
            case "Savings":
                rate = 0.05;
                break;
            case "Checking":
                rate = 0.02;
                break;
            default:
                rate = 0.01;
                break;
        }
        return balance * rate;
    }
}
