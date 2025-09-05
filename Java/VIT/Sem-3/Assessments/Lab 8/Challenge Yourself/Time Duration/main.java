class TimeDuration {
    int hours;
    int minutes;
    int seconds;

    public void display() {
        System.out.printf("Time: %d hours, %d minutes, %d seconds\n",
                hours, minutes, seconds);
    }
}

class TimeAdder {
    public static TimeDuration add(TimeDuration t1, TimeDuration t2) {
        TimeDuration result = new TimeDuration();

        result.seconds = t1.seconds + t2.seconds;
        result.minutes = t1.minutes + t2.minutes;
        result.hours = t1.hours + t2.hours;

        if (result.seconds >= 60) {
            result.minutes += result.seconds / 60;
            result.seconds = result.seconds % 60;
        }

        if (result.minutes >= 60) {
            result.hours += result.minutes / 60;
            result.minutes = result.minutes % 60;
        }

        return result;
    }
}