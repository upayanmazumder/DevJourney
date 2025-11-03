import java.io.*;
import java.util.*;

class PetActivity implements Serializable {
    String name;
    double duration;

    PetActivity(String name, double duration) {
        this.name = name;
        this.duration = duration;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String activity = sc.next();
        double duration = sc.nextDouble();
        sc.close();
        PetActivity pet = new PetActivity(activity, duration + 0.5);
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("pet_activity.ser"))) {
            out.writeObject(pet);
        } catch (IOException e) {
            return;
        }
        PetActivity obj = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("pet_activity.ser"))) {
            obj = (PetActivity) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        System.out.println(obj.duration + " hours");
    }
}
