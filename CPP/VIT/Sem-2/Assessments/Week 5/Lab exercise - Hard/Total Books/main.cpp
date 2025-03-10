#include <iostream>
#include <vector>
using namespace std;

class Category
{
public:
    int numBooks;
    Category(int n) : numBooks(n) {}
};

int calculateTotalBooks(const vector<Category> &categories)
{
    int total = 0;
    for (const auto &category : categories)
    {
        total += category.numBooks;
    }
    return total;
}

int main()
{
    int n;
    cin >> n;

    vector<Category> categories;
    for (int i = 0; i < n; i++)
    {
        int numBooks;
        cin >> numBooks;
        categories.emplace_back(numBooks); // Creates object dynamically
    }

    cout << "Total books: " << calculateTotalBooks(categories) << endl;
    return 0;
}