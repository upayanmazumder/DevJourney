import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class ValueProcessor {
    public static Map<String, Double> readValues(Scanner scanner) {
        Map<String, Double> valueMap = new HashMap<>();
        while (true) {
            String inputLine = scanner.nextLine();
            if (inputLine.equals("done")) {
                break;
            }

            if (inputLine.contains(":") == false) {
                System.out.println("Invalid format");
                return null;
            }
            if (inputLine.indexOf(':') != inputLine.lastIndexOf(':')) {
                System.out.println("Invalid format");
                return null;
            }
            if (inputLine.contains("-") || inputLine.contains("_") || inputLine.contains("=") || inputLine.contains("!")
                    || inputLine.contains("@") || inputLine.contains("#") || inputLine.contains("$")
                    || inputLine.contains("%") || inputLine.contains("^") || inputLine.contains("&")
                    || inputLine.contains("*") || inputLine.contains("(") || inputLine.contains(")")
                    || inputLine.contains("+") || inputLine.contains("`") || inputLine.contains("~")
                    || inputLine.contains("/") || inputLine.contains("\\") || inputLine.contains("<")
                    || inputLine.contains(">") || inputLine.contains("?") || inputLine.contains("[")
                    || inputLine.contains("]") || inputLine.contains("{") || inputLine.contains("}")
                    || inputLine.contains("|") || inputLine.contains(";")) {
                String temp = inputLine.substring(0, inputLine.indexOf(':'));
                if (temp.contains("-") || temp.contains("_") || temp.contains("=") || temp.contains("!")
                        || temp.contains("@") || temp.contains("#") || temp.contains("$") || temp.contains("%")
                        || temp.contains("^") || temp.contains("&") || temp.contains("*") || temp.contains("(")
                        || temp.contains(")") || temp.contains("+") || temp.contains("`") || temp.contains("~")
                        || temp.contains("/") || temp.contains("\\") || temp.contains("<") || temp.contains(">")
                        || temp.contains("?") || temp.contains("[") || temp.contains("]") || temp.contains("{")
                        || temp.contains("}") || temp.contains("|") || temp.contains(";") || temp.contains(" ")) {
                    System.out.println("Invalid format");
                    return null;
                }
            }

            String[] parts = inputLine.split(":");
            if (parts.length != 2) {
                System.out.println("Invalid format");
                return null;
            }

            try {
                String fruitName = parts[0];
                double quantity = Double.parseDouble(parts[1]);
                valueMap.put(fruitName, quantity);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input");
                return null;
            }
        }
        return valueMap;
    }

    public static double calculateSum(Map<String, Double> valueMap) {
        double sum = 0.0;
        for (double quantity : valueMap.values()) {
            sum += quantity;
        }
        return sum;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Double> valueMap = ValueProcessor.readValues(scanner);
        if (valueMap != null) {
            double sum = ValueProcessor.calculateSum(valueMap);
            System.out.printf("%.2f\n", sum);
        }
        scanner.close();
    }
}