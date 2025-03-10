#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double calculateCaloriesBurned(string ex, double d, double w, double i = 1.0) {
    transform(ex.begin(), ex.end(), ex.begin(), ::tolower);
    double rate = (ex == "running") ? 9.8 : (ex == "cycling") ? 6.7 : (ex == "swimming") ? 7.2 : 5.0;
    return d * w * rate * i;
}

int main() {
    string ex;
    double d, w, i = 1.0;
    cin >> ex >> d >> w;
    if (cin >> i); 
    cout << "You burned approximately " << fixed << setprecision(0) << calculateCaloriesBurned(ex, d, w, i) << " calories.\n";
}