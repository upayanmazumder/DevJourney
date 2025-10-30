import java.io.*;
import java.util.*;

class BankAccount implements Serializable {
    double balance;

    BankAccount(double balance) {
        this.balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double B = sc.nextDouble();
        double D = sc.nextDouble();
        double W = sc.nextDouble();
        sc.close();
        BankAccount account = new BankAccount(B);
        account.deposit(D);
        account.withdraw(W);
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("bankAccount.ser"))) {
            out.writeObject(account);
        } catch (IOException e) {
            return;
        }
        BankAccount obj = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("bankAccount.ser"))) {
            obj = (BankAccount) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        System.out.printf("%.2f", obj.balance);
    }
}
