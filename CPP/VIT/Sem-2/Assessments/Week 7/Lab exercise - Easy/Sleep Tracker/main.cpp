#include <iostream>

using namespace std;

class SleepTracker {
protected:
    int bedHour, bedMin, wakeHour, wakeMin;
public:
    virtual void input(int bh, int bm, int wh, int wm) {
        bedHour = bh;
        bedMin = bm;
        wakeHour = wh;
        wakeMin = wm;
    }
    
    virtual pair<int, int> duration() const {
        int totalBedMinutes = bedHour * 60 + bedMin;
        int totalWakeMinutes = wakeHour * 60 + wakeMin;
        if (totalWakeMinutes < totalBedMinutes) totalWakeMinutes += 24 * 60;
        int sleepMinutes = totalWakeMinutes - totalBedMinutes;
        return {sleepMinutes / 60, sleepMinutes % 60};
    }
    virtual ~SleepTracker() {}
};

class WeekdaySleep : public SleepTracker {
public:
    pair<int, int> duration() const override {
        return SleepTracker::duration();
    }
};

class WeekendSleep : public SleepTracker {
public:
    pair<int, int> duration() const override {
        return SleepTracker::duration();
    }
};

int main() {
    int bh1, bm1, wh1, wm1, bh2, bm2, wh2, wm2;
    cin >> bh1 >> bm1 >> wh1 >> wm1 >> bh2 >> bm2 >> wh2 >> wm2;
    
    WeekdaySleep weekday;
    WeekendSleep weekend;
    
    weekday.input(bh1, bm1, wh1, wm1);
    weekend.input(bh2, bm2, wh2, wm2);
    
    pair<int, int> weekdayDuration = weekday.duration();
    pair<int, int> weekendDuration = weekend.duration();
    
    cout << "Weekday: " << weekdayDuration.first << "h " << weekdayDuration.second << "m\n";
    cout << "Weekend: " << weekendDuration.first << "h " << weekendDuration.second << "m\n";
    
    if (weekdayDuration > weekendDuration) {
        cout << "User slept more on weekdays.";
    } else if (weekdayDuration < weekendDuration) {
        cout << "User slept more on the weekend.";
    } else {
        cout << "User slept the same amount on weekdays and weekend.";
    }
    
    return 0;
}