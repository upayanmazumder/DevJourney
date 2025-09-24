import java.util.Scanner;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String startDateStr = sc.nextLine();
        String endDateStr = sc.nextLine();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        LocalDate startDate = LocalDate.parse(startDateStr, formatter);
        LocalDate endDate = LocalDate.parse(endDateStr, formatter);
        long days;
        if (startDate.isBefore(endDate) || startDate.isEqual(endDate)) {
            days = ChronoUnit.DAYS.between(startDate, endDate);
        } else {
            days = ChronoUnit.DAYS.between(endDate, startDate);
        }
        System.out.println(days + " days");
    }
}