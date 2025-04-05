#include <iostream>
#include <list>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N > 15) {
        cout << "-1" << endl;
        return 0;
    }

    list<int> numbers;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    set<int> uniqueNumbers(numbers.begin(), numbers.end());

    int sum = 0;
    for (int val : uniqueNumbers) {
        sum += val;
    }

    cout << "Sum of unique elements: " << sum << endl;
    return 0;
}