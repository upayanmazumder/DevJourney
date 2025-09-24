import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String startDateString = scanner.next();
        String endDateString = scanner.next();
        scanner.close();

        LocalDate startDate = LocalDate.parse(startDateString);
        LocalDate endDate = LocalDate.parse(endDateString);

        if (startDate.isAfter(endDate)) {
            LocalDate temp = startDate;
            startDate = endDate;
            endDate = temp;
        }

        long daysBetween = ChronoUnit.DAYS.between(startDate, endDate);
        long weeks = daysBetween / 7;

        System.out.println(weeks + " weeks");
    }
}
