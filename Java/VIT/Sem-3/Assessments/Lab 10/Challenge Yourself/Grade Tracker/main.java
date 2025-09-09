class Student {
    private int totalMarks = 0;
    private int subjects = 0;
    private String name;

    public Student(String name) {
        this.name = name;
    }

    public void addMarks(int marks) {
        totalMarks += marks;
        subjects++;
    }

    public void addMarks(int marks1, int marks2) {
        totalMarks += marks1 + marks2;
        subjects += 2;
    }

    public double calculateAverage() {
        if (subjects == 0)
            return 0.0;
        return (double) totalMarks / subjects;
    }

    public double calculateAverage(int bonus) {
        if (subjects == 0)
            return 0.0;
        return (double) (totalMarks + bonus) / subjects;
    }

    public String calculateGrade(int marks) {
        if (marks >= 90)
            return "Excellent";
        else if (marks >= 80)
            return "Good";
        else if (marks >= 70)
            return "Average";
        else if (marks >= 60)
            return "Below Average";
        else
            return "Fail";
    }
}
