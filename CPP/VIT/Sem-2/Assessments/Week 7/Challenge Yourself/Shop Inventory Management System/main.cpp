#include <iostream>

using namespace std;

class Shop {
public:
    virtual void setPrice(int id, int price) = 0;
    virtual void displayPrice() const = 0;
    virtual ~Shop() {}
};

class ConcreteShop : public Shop {
private:
    int itemId[10], itemPrice[10];
    int itemCount;

public:
    ConcreteShop() : itemCount(0) {}

    void setPrice(int id, int price) override {
        if (itemCount < 10) {
            itemId[itemCount] = id;
            itemPrice[itemCount] = price;
            itemCount++;
        }
    }

    void displayPrice() const override {
        for (int i = 0; i < itemCount; i++) {
            cout << "The Price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    ConcreteShop dukaan;
    for (int i = 0; i < n; i++) {
        int id, price;
        cin >> id >> price;
        dukaan.setPrice(id, price);
    }

    dukaan.displayPrice();
    return 0;
}