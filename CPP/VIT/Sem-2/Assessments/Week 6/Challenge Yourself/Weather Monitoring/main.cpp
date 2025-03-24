#include <iostream>
#include <string>

using namespace std;

class WeatherData {
public:
    double value;

    WeatherData(double val) : value(val) {}
};

class TemperatureData : public WeatherData {
public:
    TemperatureData(double temp) : WeatherData(temp) {}

    string classifyTemperature() {
        return (value > 30.0) ? "Hot" : "Cool";
    }
};

class HumidityData : public WeatherData {
public:
    HumidityData(double humidity) : WeatherData(humidity) {}

    string classifyHumidity() {
        return (value > 60.0) ? "Humid" : "Dry";
    }
};

class MonitoringStation : public TemperatureData, public HumidityData {
public:
    MonitoringStation(double temp, double humidity)
        : TemperatureData(temp), HumidityData(humidity) {}

    void displayWeatherCondition() {
        cout << "Weather Condition: " << classifyTemperature() << " and " << classifyHumidity() << endl;
    }
};

int main() {
    double temperature, humidity;
    cin >> temperature >> humidity;
    MonitoringStation station(temperature, humidity);
    station.displayWeatherCondition();
    return 0;
}