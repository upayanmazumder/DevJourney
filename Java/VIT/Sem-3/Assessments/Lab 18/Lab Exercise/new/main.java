import java.util.ArrayList;
import java.util.Scanner;

class NameManager {
    private ArrayList<String> students;

    public NameManager() {
        students = new ArrayList<>();
    }

    public void addName(String name) {
        students.add(name);
    }

    public String getNameAtIndex(int index) {
        if (index >= 0 && index < students.size()) {
            return students.get(index);
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        NameManager manager = new NameManager();

        for (int i = 0; i < n; i++) {
            String name = sc.nextLine();
            manager.addName(name);
        }

        int index = sc.nextInt();
        String result = manager.getNameAtIndex(index);

        if (result != null) {
            System.out.println("Element at index " + index + ": " + result);
        } else {
            System.out.println("Invalid index");
        }
        sc.close();
    }
}