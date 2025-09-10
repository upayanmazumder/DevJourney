class GrandFather {
    protected int grandFatherAge;

    void setGrandFatherAge(int age) {
        this.grandFatherAge = age;
    }

    void setGrandfatherAge(int age) {
        setGrandFatherAge(age);
    }
}

class Father extends GrandFather {
    protected int fatherAge;

    void setFatherAge(int age) {
        this.fatherAge = age;
    }

    int calculateFatherAgeAfter5Years() {
        return fatherAge + 5;
    }
}

class Son extends Father {

    private int sonAge;

    void setSonAge(int age) {
        this.sonAge = age;
    }

    int calculateGrandfatherSonAgeDifference() {
        return grandFatherAge - sonAge;
    }
}
