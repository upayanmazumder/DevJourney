#include <iostream>
#include <string>
using namespace std;

class Calculator {
    int N;
    string type;

public:
    Calculator(string t, int n) : type(t), N(n) {}

    int calculateSum() {
        int sum = 0, num = (type == "odd") ? 1 : 2;
        for (int i = 0; i < N; i++) {
            sum += num;
            num += 2;
        }
        return sum;
    }
};

int main() {
    string type;
    int N;
    cin >> type >> N;

    Calculator calc(type, N);
    cout << calc.calculateSum() << endl;

    return 0;
}