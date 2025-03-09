#include <iostream>
#include <iomanip>

class Shop
{
    static double totalSales;

public:
    static void addSale(double amount)
    {
        totalSales += amount;
    }

    static void displayTotalSales()
    {
        std::cout << "Total Sales: " << std::fixed << std::setprecision(2) << totalSales << std::endl;
    }
};

double Shop::totalSales = 0.0;

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        double salesAmount;
        std::cin >> salesAmount;
        Shop::addSale(salesAmount);
    }

    Shop::displayTotalSales();
    return 0;
}