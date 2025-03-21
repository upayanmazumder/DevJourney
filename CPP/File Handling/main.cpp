#include <iostream>
#include <fstream>
using namespace std;

class FileManager {
public:
    void writeToFile(string name, int age) {
        ofstream file("data.txt");
        file << name << " " << age;
        file.close();
    }

    void readFromFile() {
        ifstream file("data.txt");
        string name;
        int age;
        file >> name >> age;
        cout << "Name: " << name << ", Age: " << age << endl;
        file.close();
    }
};

int main() {
    FileManager fm;
    fm.writeToFile("Alice", 25);
    fm.readFromFile();
    return 0;
}
