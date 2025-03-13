#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Device {
protected:
    string brand;
    double price;

public:
    Device(string brand, double price) : brand(brand), price(price) {}

    virtual void display(bool isRefrigerator = false) {
        cout << "Device: " << brand << ", Price: $" 
             << fixed << setprecision(isRefrigerator ? 1 : 2) 
             << (isRefrigerator ? std::round(price) : price) << endl;
    }
};

class Television : public Device {
private:
    int screenSize;

public:
    Television(string brand, double price, int screenSize)
        : Device(brand, price), screenSize(screenSize) {}

    void calculatePixelDensity(int resolutionWidth, int resolutionHeight) {
        double screenSizeCm = screenSize * 2.54;
        double pixelDensity = (resolutionWidth * resolutionHeight) / (screenSizeCm * screenSizeCm);
        
        cout << "Screen Size: " << screenSize << " inches (" << fixed << setprecision(1) << screenSizeCm << " cm)" << endl;
        cout << "Pixel Density: " << fixed << setprecision(1) << pixelDensity << " pixels per square centimeter" << endl;
    }
};

class Refrigerator : public Device {
private:
    int capacity;

public:
    Refrigerator(string brand, double price, int capacity)
        : Device(brand, price), capacity(capacity) {}

    void calculateEnergyEfficiency(double energyConsumption) {
        double capacityCubicFeet = capacity * 0.0353;
        double energyEfficiency = energyConsumption / capacityCubicFeet;

        cout << "Capacity: " << capacity << " liters (" << fixed << setprecision(1) << capacityCubicFeet << " cubic feet)" << endl;
        cout << "Energy Efficiency: " << fixed << setprecision(1) << energyEfficiency << " kWh per cubic foot" << endl;
    }
};

int main() {
    string tvBrand, fridgeBrand;
    double tvPrice, fridgePrice, energyConsumption;
    int tvScreenSize, fridgeCapacity, resolutionWidth, resolutionHeight;

    // Reading input
    cin >> tvBrand >> tvPrice >> tvScreenSize;
    cin >> fridgeBrand >> fridgePrice >> fridgeCapacity;
    cin >> resolutionWidth >> resolutionHeight;
    cin >> energyConsumption;

    // Creating objects
    Television tv(tvBrand, tvPrice, tvScreenSize);
    Refrigerator fridge(fridgeBrand, fridgePrice, fridgeCapacity);

    // Display results
    cout << "Television Information:" << endl;
    tv.display();
    tv.calculatePixelDensity(resolutionWidth, resolutionHeight);

    cout << endl << "Refrigerator Information:" << endl;
    fridge.display(true);
    fridge.calculateEnergyEfficiency(energyConsumption);

    return 0;
}