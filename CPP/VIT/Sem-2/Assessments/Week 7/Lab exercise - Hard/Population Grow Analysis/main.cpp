#include <iostream>
#include <iomanip>
using namespace std;

class Popul {
protected:
    int initialPop, finalPop;

public:
    virtual void calcRate(int N, int P) {
        initialPop = N;
        finalPop = P;
    }
};

class Birth : public Popul {
public:
    void calcRate(int N, int P) override {
        Popul::calcRate(N, P);
        double growthRate = (1000.0 * (finalPop - initialPop)) / initialPop;
        cout << fixed << setprecision(2) << growthRate << endl;
    }
};

int main() {
    int N, P;
    cin >> N >> P;
    Birth obj;
    obj.calcRate(N, P);
    return 0;
}