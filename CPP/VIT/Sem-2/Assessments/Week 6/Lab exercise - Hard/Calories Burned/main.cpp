#include <iostream>
#include <cmath>
using namespace std;

class Exercise {
protected:
    int duration, weight;

public:
    Exercise(int d, int w) : duration(d), weight(w) {}
    virtual int calculateCaloriesBurned() = 0;
    virtual ~Exercise() {}
};

class Cardio : public Exercise {
private:
    int intensity;

public:
    Cardio(int d, int w, int i) : Exercise(d, w), intensity(i) {}

    int calculateCaloriesBurned() override {
        double caloriesPerMinute = (8.0 * intensity * weight) / 200.0;
        return round(caloriesPerMinute * duration);
    }
};

class Weightlifting : public Exercise {
private:
    int repetitions;

public:
    Weightlifting(int d, int w, int r) : Exercise(d, w), repetitions(r) {}

    int calculateCaloriesBurned() override {
        double caloriesPerRep = (5.0 * weight) / 100.0;
        return round(caloriesPerRep * repetitions * duration);
    }
};

class Cycling : public Exercise {
private:
    int speed;

public:
    Cycling(int d, int w, int s) : Exercise(d, w), speed(s) {}

    int calculateCaloriesBurned() override {
        double caloriesPerMinute = (10.0 * speed * weight) / 500.0;
        return round(caloriesPerMinute * duration);
    }
};

int main() {
    int duration, weight, type;
    cin >> duration >> weight >> type;
    
    if (type == 1) {
        int intensity;
        cin >> intensity;
        Cardio c(duration, weight, intensity);
        cout << "Total calories burned: " << c.calculateCaloriesBurned() << " calories" << endl;
    } else if (type == 2) {
        int repetitions;
        cin >> repetitions;
        Weightlifting w(duration, weight, repetitions);
        cout << "Total calories burned: " << w.calculateCaloriesBurned() << " calories" << endl;
    } else if (type == 3) {
        int speed;
        cin >> speed;
        Cycling cy(duration, weight, speed);
        cout << "Total calories burned: " << cy.calculateCaloriesBurned() << " calories" << endl;
    }

    return 0;
}