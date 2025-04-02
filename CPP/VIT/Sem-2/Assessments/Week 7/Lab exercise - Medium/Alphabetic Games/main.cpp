#include <iostream>
using namespace std;

class Alphabetics {
public:
    virtual void game(char a, char b, char c, char d) = 0;
    virtual ~Alphabetics() {}
};

class Game : public Alphabetics {
public:
    void game(char a, char b, char c, char d) override {
        int score = 0;
        char letters[] = {a, b, c, d};

        for (char ch : letters) {
            if (isupper(ch))
                score += 10;
            else if (islower(ch))
                score -= 5;
        }

        cout << "Score : " << score << endl;
    }
};

int main() {
    char a, b, c, d;
    cin >> a >> b >> c >> d;

    Game g;
    g.game(a, b, c, d);

    return 0;
}