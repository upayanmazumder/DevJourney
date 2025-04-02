#include <iostream>
using namespace std;

void add(string inp_type, string inp1) {
    if (inp_type == "int") 
        cout << stoi(inp1) << endl;
    else 
        cout << inp1 << endl;
}

void add(string inp_type, string inp1, string inp2) {
    if (inp_type == "int") 
        cout << stoi(inp1) + stoi(inp2) << endl;
    else 
        cout << inp1 + inp2 << endl;
}

void add(string inp_type, string inp1, string inp2, string inp3) {
    if (inp_type == "int") 
        cout << stoi(inp1) + stoi(inp2) + stoi(inp3) << endl;
    else 
        cout << inp1 + inp2 + inp3 << endl;
}

int main() {
    string inp_type, inp1, inp2, inp3;
    cin >> inp_type >> inp1 >> inp2 >> inp3;

    add(inp_type, inp1);
    add(inp_type, inp1, inp2);
    add(inp_type, inp1, inp2, inp3);

    return 0;
}