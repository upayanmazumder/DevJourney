#include <iostream>
#include <iomanip>

using namespace std;
class UnitConverter {
public:
double convert(double millimetres) {
return millimetres / 10.0;
}
double convert(int unitType, double value) {
    if (unitType == 2) return value / 1000000.0;
    return -1;
}

};
int main() {
int unitType;
double value;
cin >> unitType;
if (!(cin >> value)) {
cout << "Invalid unit type!";
return 0;
}
UnitConverter converter;
if (unitType == 1) {
    cout << fixed << setprecision(2) << converter.convert(value) << " cm";
} else if (unitType == 2) {
    cout << fixed << setprecision(2) << converter.convert(unitType, value) << " km";
} else {
    cout << "Invalid unit type!";
}

return 0;

}
