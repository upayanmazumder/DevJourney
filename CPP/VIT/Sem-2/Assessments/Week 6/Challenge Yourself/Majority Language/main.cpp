#include <iostream>
#include <iomanip>

using namespace std;

class Language {
public:
    int totalPopulation;

    Language(int population) : totalPopulation(population) {}
};

class English : public Language {
public:
    int englishSpeakers;

    English(int population, int engSpeakers) : Language(population), englishSpeakers(engSpeakers) {}

    void EnglishPercentageStatus() {
        double percentage = (double) englishSpeakers / totalPopulation * 100;
        cout << "English Percentage: " << fixed << setprecision(1) << percentage << "%" << endl;
        if (percentage >= 75) {
            cout << "English is Majority!" << endl;
        } else {
            cout << "English is not Majority!" << endl;
        }
    }
};

class Spanish : public Language {
public:
    int spanishSpeakers;

    Spanish(int population, int spnSpeakers) : Language(population), spanishSpeakers(spnSpeakers) {}

    void SpanishPercentageStatus() {
        double percentage = (double) spanishSpeakers / totalPopulation * 100;
        cout << "Spanish Percentage: " << fixed << setprecision(1) << percentage << "%" << endl;
        if (percentage >= 75) {
            cout << "Spanish is Majority!" << endl;
        } else {
            cout << "Spanish is not Majority!" << endl;
        }
    }
};

int main() {
    int totalPop, engPop, spnPop;
    
    cin >> totalPop >> engPop >> spnPop;

    English englishObj(totalPop, engPop);
    Spanish spanishObj(totalPop, spnPop);

    englishObj.EnglishPercentageStatus();
    spanishObj.SpanishPercentageStatus();

    return 0;
}