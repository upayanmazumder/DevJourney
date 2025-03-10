#include <iostream>
#include <iomanip>

class Temperature
{
public:
    float temp;
    Temperature(float t) : temp(t) {}
};

int main()
{
    float f, c;
    std::cin >> f >> c;

    Temperature fahrenheit(f);
    Temperature celsius(c);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << (fahrenheit.temp - 32) * 5 / 9 << " degree celsius" << std::endl;
    std::cout << (celsius.temp * 9 / 5) + 32 << " degree fahrenheit" << std::endl;

    return 0;
}