#include <iostream>
using namespace std;

class Weather {
public:
    float t;
    string c;
    Weather(float a, string b) : t(a), c(b) {}
};

void compare(Weather h, Weather c) {
    if (c.t > h.t) cout << "Warmer\n";
    else if (c.t < h.t) cout << "Colder\n";
    else cout << "Same temperature\n";

    if (c.c == h.c) cout << "Same conditions: " << c.c << endl;
    else cout << "Conditions changing to: " << c.c << endl;
}

int main() {
    float ht, ct;
    string hc, cc;
    cin >> ht;
    cin.ignore();
    getline(cin, hc);
    cin >> ct;
    cin.ignore();
    getline(cin, cc);
    compare(Weather(ht, hc), Weather(ct, cc));
}