#include <iostream>
#include <iomanip>
using namespace std;

class Forest {
public:
    double annualRainfall;

    Forest(double sideLength, double rainfallInMM) {
        annualRainfall = sideLength * sideLength * rainfallInMM;
    }

    Forest(double length, double width, double rainfallInMM) {
        annualRainfall = length * width * rainfallInMM;
    }

    void displayRainfall() {
        cout << fixed << setprecision(2) << annualRainfall << " mm" << endl;
    }
};

int main() {
    double sideLength, squareRainfall, length, width, rectRainfall;
    cin >> sideLength >> squareRainfall;
    Forest squareForest(sideLength, squareRainfall);
    squareForest.displayRainfall();

    cin >> length >> width >> rectRainfall;
    Forest rectForest(length, width, rectRainfall);
    rectForest.displayRainfall();

    return 0;
}