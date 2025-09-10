class AgeCalculatorFunctions {
    int birthYear;
    int currentYear;

    AgeCalculatorFunctions(int birthYear, int currentYear) {
        this.birthYear = birthYear;
        this.currentYear = currentYear;
    }

    int calculateLeapYears() {
        int count = 0;
        for (int year = birthYear; year <= currentYear; year++) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                count++;
            }
        }
        return count;
    }
}