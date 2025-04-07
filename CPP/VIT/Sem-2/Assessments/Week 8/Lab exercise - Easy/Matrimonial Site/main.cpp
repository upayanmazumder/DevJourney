#include <iostream>
using namespace std;

template <size_t N>
int calculateCompatibilityScore(int (&profile1)[N], int (&profile2)[N]) {
    int score = 0;
    for (size_t i = 0; i < N; ++i) {
        if (profile1[i] == profile2[i]) {
            score += 10;
        }
    }
    return score;
}

int main() {
    const int N = 3;
    int profile1[N], profile2[N];

    for (int i = 0; i < N; ++i) {
        cin >> profile1[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> profile2[i];
    }

    int score = calculateCompatibilityScore(profile1, profile2);
    cout << "Compatibility Score: " << score << endl;

    return 0;
}