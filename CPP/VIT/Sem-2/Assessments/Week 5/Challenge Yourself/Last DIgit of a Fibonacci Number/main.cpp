#include <iostream>
using namespace std;

void fiboLastDigit(int n, int &lastDigit) {
    if (n == 1) {
        lastDigit = 0;
        return;
    } 
    if (n == 2) {
        lastDigit = 1;
        return;
    }
    
    int a = 0, b = 1;
    for (int i = 3; i <= n; i++) {
        int temp = (a + b) % 10;
        a = b;
        b = temp;
    }
    lastDigit = b;
}

int main() {
    int n, result;
    cin >> n;
    fiboLastDigit(n, result);
    cout << result << endl;
    return 0;
}