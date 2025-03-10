#include <iostream>
#include <iomanip>
using namespace std;

double calculateRoomCharges(int t, int n) {
    if (t == 1) return 100.0 * n;
    if (t == 2) return 150.0 * n;
    if (t == 3) return 250.0 * n;
    return -1;
}

double calculateMealExpenses(int m) {
    return m ? 30.0 : 0.0;
}

double calculateServiceCosts(int s) {
    return s ? 50.0 : 0.0;
}

int main() {
    int t, n, m, s;
    cin >> t >> n >> m >> s;
    double room = calculateRoomCharges(t, n);
    if (room == -1) {
        cout << "No rooms\nTotal cost of stay: Rs. 0.00\n";
        return 0;
    }
    double total = room + calculateMealExpenses(m) + calculateServiceCosts(s);
    cout << fixed << setprecision(2) << "Total cost of stay: Rs. " << total << "\n";
}