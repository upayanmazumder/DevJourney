package Java.Basics;

import java.util.Scanner;

public class scan {

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("What is your name?");
        String name = scanner.nextLine();
        System.out.println("How old are you?");
        int age = scanner.nextInt();
        scanner.nextLine(); //This is needed to clear the buffer
        System.out.println("What is your favourite food?");
        String food = scanner.nextLine();

        System.out.println("Hello, "+name);
        System.out.println("You are "+age+" years old");
        System.out.println("You like "+food);

    }
    
}
