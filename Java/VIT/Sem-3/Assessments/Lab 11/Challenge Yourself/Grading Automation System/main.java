class Student {
    protected String name;
    protected int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class Undergraduate extends Student {
    protected double creditsCompleted;

    public Undergraduate(String name, int age, double creditsCompleted) {
        super(name, age);
        this.creditsCompleted = creditsCompleted;
    }

    public double calculateGPA() {
        double gpa = 4.0 * (creditsCompleted / 120.0);
        if (gpa > 4.0)
            gpa = 4.0;
        return gpa;
    }

    public String getClassStanding() {
        if (creditsCompleted < 30)
            return "Freshman";
        else if (creditsCompleted < 60)
            return "Sophomore";
        else if (creditsCompleted < 90)
            return "Junior";
        else
            return "Senior";
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.printf("Credits Completed: %.1f\n", creditsCompleted);
    }
}

class ComputerScienceMajor extends Undergraduate {
    public ComputerScienceMajor(String name, int age, double creditsCompleted) {
        super(name, age, creditsCompleted);
    }
}