#include <iostream>
#include <iomanip>

using namespace std;

class Plant {
public:
    int count;
    float pricePerUnit;
    float discountPercentage;

    Plant(int n, float price, float discount) : count(n), pricePerUnit(price), discountPercentage(discount) {}
};

class Discount : public Plant {
public:
    Discount(int n, float price, float discount) : Plant(n, price, discount) {}

    float calculateFinalPrice() {
        float discountedPrice = (1 - (discountPercentage / 100)) * pricePerUnit;
        return count * discountedPrice;
    }
};

class Nursery : public Plant {
public:
    float rating;

    Nursery(int n, float price, float discount, float ratingValue) : Plant(n, price, discount), rating(ratingValue) {}

    void categorizePlant() {
        if (rating >= 0.1 && rating <= 2.5)
            cout << "Average" << endl;
        else if (rating >= 2.6 && rating <= 5.0)
            cout << "Excellent" << endl;
    }
};

int main() {
    int n;
    float price, discount, rating;

    cin >> n >> price >> discount >> rating;

    Discount discountObj(n, price, discount);
    Nursery nurseryObj(n, price, discount, rating);

    cout << "Final Price: " << fixed << setprecision(2) << discountObj.calculateFinalPrice() << endl;

    nurseryObj.categorizePlant();

    return 0;
}