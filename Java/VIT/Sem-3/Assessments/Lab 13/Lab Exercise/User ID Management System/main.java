import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            int n = Integer.parseInt(sc.nextLine());
            if (n < 1 || n > 500)
                throw new IllegalArgumentException("Error: Number of user IDs must be between 1 and 500");
            int[] userIDs = new int[n];
            for (int j = 0; j < n; j++) {
                userIDs[j] = Integer.parseInt(sc.nextLine());
            }
            int i = Integer.parseInt(sc.nextLine());
            int s = Integer.parseInt(sc.nextLine());
            System.out.println(userIDs[i]);
            userIDs[i] = s;
            System.out.println(userIDs[i]);
        } catch (NumberFormatException e) {
            System.out.println("Error: Please enter valid integer values for user IDs");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Invalid index. Please select a valid index from the list");
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}