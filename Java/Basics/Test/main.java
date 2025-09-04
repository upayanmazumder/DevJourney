
class Sample {
    int num = 3;

    void doubleIt() {
        num = num * 2;
    }
}

class Main {
    public static void main(String[] args) {
        Sample s = new Sample();
        System.out.println(s.num);
        s.doubleIt();
        System.out.println(s.num);
    }
}