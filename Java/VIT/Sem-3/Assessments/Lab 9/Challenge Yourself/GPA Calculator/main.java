class GPACalculator {
    private double[] grades;
    private double gpa;

    public GPACalculator(double[] grades) {
        this.grades = grades;
        this.gpa = calculateGPA();
    }

    private double calculateGPA() {
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.length;
    }

    public double getGPA() {
        return this.gpa;
    }

    public boolean isEligibleForScholarship() {
        return this.gpa >= 3.5 && grades.length >= 5;
    }
}
