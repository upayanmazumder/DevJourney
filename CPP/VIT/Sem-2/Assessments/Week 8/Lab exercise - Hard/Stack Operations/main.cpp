#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class StackDerived {
    vector<T> stack;
public:
    void push(T value) {
        stack.push_back(value);
    }

    void pop() {
        if (stack.empty()) {
            cout << "Stack underflow!" << endl;
        } else {
            stack.pop_back();
        }
    }

    void display() {
        cout << "Stack elements: ";
        for (int i = stack.size() - 1; i >= 0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return stack.empty();
    }
};

int main() {
    int n;
    cin >> n;
    StackDerived<int> intStack;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        intStack.push(x);
    }

    intStack.display();
    intStack.pop();
    intStack.display();

    int m;
    cin >> m;
    StackDerived<double> doubleStack;
    for (int i = 0; i < m; ++i) {
        double y;
        cin >> y;
        doubleStack.push(y);
    }

    doubleStack.display();
    doubleStack.pop();
    doubleStack.display();

    return 0;
}