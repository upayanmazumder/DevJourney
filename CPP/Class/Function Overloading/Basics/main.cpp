class Math {
    public:
        int add(int a, int b) {
            return a + b;
        }
        double add(double a, double b) {
            return a + b;
        }
    };
    
    int main() {
        Math m;
        cout << m.add(5, 10) << endl;       // Calls int version
        cout << m.add(5.5, 2.2) << endl;   // Calls double version
        return 0;
    }
    