#include <stdio.h>

union WeatherForecast {
    double temperature;
    double precipitation;
};

int main() {
    union WeatherForecast weather1, weather2;
    double temp1, prec1, temp2, prec2;
    scanf("%lf %lf", &temp1, &prec1);
    scanf("%lf %lf", &temp2, &prec2);
    double avgTemp = (temp1 + temp2) / 2.0;
    double avgPrec = (prec1 + prec2) / 2.0;
    printf("%.2f degree celsius\n", avgTemp);
    printf("%.2f mm\n", avgPrec);
    
    if (avgTemp >= 25.0 && avgPrec < 10.0) {
        printf("Sunny\n");
    } else if (avgPrec >= 10.0) {
        printf("Rainy\n");
    } else {
        printf("Cloudy\n");
    }
    return 0;
}