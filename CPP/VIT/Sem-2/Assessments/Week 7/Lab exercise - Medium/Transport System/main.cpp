#include <iostream>
#include <cmath>
using namespace std;

class Transport {
public:
    virtual void operate(int start, int destination) = 0;
    virtual ~Transport() {}
};

class TransportA : public Transport {
public:
    void operate(int start, int destination) override {
        int timeTaken = abs(start - destination) * 2;
        cout << "Time taken: " << timeTaken << " seconds" << endl;
    }
};

class TransportB : public Transport {
public:
    void operate(int start, int destination) override {
        int timeTaken = abs(start - destination) * 3;
        cout << "Time taken: " << timeTaken << " seconds" << endl;
    }
};

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char transportType;
        int start, destination;
        cin >> transportType >> start >> destination;

        Transport* transport = nullptr;
        
        if (transportType == 'P' || transportType == 'p') {
            transport = new TransportA();
        } else if (transportType == 'F' || transportType == 'f') {
            transport = new TransportB();
        }

        if (transport) {
            transport->operate(start, destination);
            delete transport;
        }
    }

    return 0;
}