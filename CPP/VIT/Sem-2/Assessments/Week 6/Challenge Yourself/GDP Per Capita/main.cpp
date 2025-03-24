#include <iostream>
#include <iomanip>

using namespace std;

class Population {
protected:
    long long totalPopulation;

public:
    Population(long long population) : totalPopulation(population) {}
};

class GDP {
protected:
    double gdpValue;

public:
    GDP(double gdp) : gdpValue(gdp) {}
};

class Country : public Population, public GDP {
public:
    Country(long long population, double gdp) : Population(population), GDP(gdp) {}

    double calculateGDPPerCapita() {
        return gdpValue / totalPopulation;
    }

    void displayGDPPerCapita() {
        cout << "GDP: " << fixed << setprecision(2) << calculateGDPPerCapita() << endl;
    }
};

int main() {
    long long population;
    double gdp;

    cin >> population >> gdp;

    Country country(population, gdp);
    country.displayGDPPerCapita();

    return 0;
}