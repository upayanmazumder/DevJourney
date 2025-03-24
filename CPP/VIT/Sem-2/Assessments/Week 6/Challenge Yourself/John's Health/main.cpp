#include <iostream>
#include <iomanip>

using namespace std;

class BMI {
protected:
    double weight, height;

public:
    BMI(double w, double h) : weight(w), height(h) {}

    double calculateBMI() {
        return weight / (height * height);
    }
};

class BloodPressure {
protected:
    int systolic, diastolic;

public:
    BloodPressure(int sys, int dia) : systolic(sys), diastolic(dia) {}
};

class Health : public BMI, public BloodPressure {
public:
    Health(double w, double h, int sys, int dia)
        : BMI(w, h), BloodPressure(sys, dia) {}

    void assessHealth() {
        double bmi = calculateBMI();
        cout << "BMI: " << fixed << setprecision(2) << bmi << endl;

        if (bmi < 18.5 && systolic < 90 && diastolic < 60)
            cout << "Health Status: Underweight with Low Blood Pressure" << endl;
        else if (bmi >= 18.5 && bmi < 24.9 && systolic >= 90 && systolic <= 120 && diastolic >= 60 && diastolic <= 80)
            cout << "Health Status: Healthy Weight with Normal Blood Pressure" << endl;
        else if (bmi >= 25.0 && bmi < 29.9 && systolic > 120 && diastolic > 80)
            cout << "Health Status: Overweight with High Blood Pressure" << endl;
        else
            cout << "Health Status: Health Risk Undefined" << endl;
    }
};

int main() {
    double weight, height;
    int systolic, diastolic;

    cin >> weight >> height >> systolic >> diastolic;

    Health john(weight, height, systolic, diastolic);
    john.assessHealth();

    return 0;
}