import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        int age = Integer.parseInt(sc.nextLine().trim());
        String type = sc.nextLine().trim();
        double basePremium = Double.parseDouble(sc.nextLine().trim());

        double finalPremium = basePremium;
        if (age > 50)
            finalPremium += basePremium * 0.2;
        else if (age >= 30)
            finalPremium += basePremium * 0.1;

        if (type.equalsIgnoreCase("Life"))
            finalPremium += 500;
        else if (type.equalsIgnoreCase("Health"))
            finalPremium += 300;

        System.out.println(basePremium);
        System.out.println(finalPremium);
    }
}
