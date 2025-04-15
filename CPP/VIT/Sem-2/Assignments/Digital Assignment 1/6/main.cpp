#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many people: ";
    cin >> n;

    vector<Person> people(n);

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "th person ->" << endl; 
        cout << "\tName: ";
        cin >> ws;
        getline(cin, people[i].name);

        cout << "\tAge: ";
        cin >> people[i].age;
    }

    Person youngest = people[0];
    for (int i = 1; i < n; ++i) {
        if (people[i].age < youngest.age) {
            youngest = people[i];
        }
    }

    cout << youngest.name << " is youngest at " << youngest.age << " years" <<  endl;

    return 0;
}
