#include <iostream>
#include <list>
using namespace std;

int main() {
    int N, target;
    cin >> N;

    list<int> numbers;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    cin >> target;

    numbers.remove(target);

    for (int num : numbers) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}