import java.util.Scanner;

class Mythread extends Thread {
    private String str;

    public Mythread(String str) {
        this.str = str;
    }

    public void run() {
        int[] freq = new int[256];
        for (char c : str.toCharArray()) {
            freq[c]++;
        }
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                System.out.println((char) i + "" + freq[i]);
            }
        }
    }
}

class CharacterFrequency {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        Mythread[] threads = new Mythread[n];

        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            threads[i] = new Mythread(s);
        }

        for (int i = 0; i < n; i++) {
            threads[i].start();
        }

        for (int i = 0; i < n; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
