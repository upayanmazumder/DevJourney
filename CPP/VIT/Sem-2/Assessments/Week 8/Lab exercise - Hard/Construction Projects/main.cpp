#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

template <typename T, typename U>
void addMaterial(map<T, U>& inventory, vector<T>& order, T name, U quantity) {
    if (inventory.find(name) == inventory.end()) {
        order.push_back(name);
    }
    inventory[name] = quantity;
    cout << "Added " << quantity << " units of " << name << " to the inventory. ";
}

template <typename T, typename U>
void updateMaterial(map<T, U>& inventory, T name, U quantity) {
    if (inventory.find(name) != inventory.end()) {
        inventory[name] = quantity;
        cout << "Updated " << name << " quantity to " << quantity << " units in the inventory. ";
    } else {
        cout << "Material " << name << " not found in the inventory. ";
    }
}

template <typename T, typename U>
void displayInventory(const map<T, U>& inventory, const vector<T>& order) {
    cout << "Current Inventory Status: ";
    for (const auto& name : order) {
        cout << name << ": " << inventory.at(name) << " units ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    map<string, int> inventory;
    vector<string> order;
    string name;
    int quantity;

    for (int i = 0; i < n; ++i) {
        cin >> name >> quantity;
        addMaterial(inventory, order, name, quantity);
    }
   
    cin >> name >> quantity;
    updateMaterial(inventory, name, quantity);
   
    displayInventory(inventory, order);

    return 0;
}