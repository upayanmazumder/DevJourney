#include <iostream>
#include <iomanip>

using namespace std;

class Experiment {
public:
    virtual void analyzeResults() = 0;
    virtual ~Experiment() {}
};

class ChemistryExperiment : public Experiment {
private:
    double reactantA, reactantB;
public:
    ChemistryExperiment(double a, double b) : reactantA(a), reactantB(b) {}
    void analyzeResults() override {
        cout << fixed << setprecision(2) << (reactantA * reactantB) << endl;
    }
};

class PhysicsExperiment : public Experiment {
private:
    double initialVelocity, acceleration, time;
public:
    PhysicsExperiment(double u, double a, double t) : initialVelocity(u), acceleration(a), time(t) {}
    void analyzeResults() override {
        cout << fixed << setprecision(2) << (initialVelocity + (acceleration * time)) << " m/s" << endl;
    }
};

int main() {
    char experimentType;
    cin >> experimentType;

    if (experimentType == 'C' || experimentType == 'c') {
        double a, b;
        cin >> a >> b;
        ChemistryExperiment chem(a, b);
        chem.analyzeResults();
    } else if (experimentType == 'P' || experimentType == 'p') {
        double u, a, t;
        cin >> u >> a >> t;
        PhysicsExperiment phys(u, a, t);
        phys.analyzeResults();
    }

    return 0;
}