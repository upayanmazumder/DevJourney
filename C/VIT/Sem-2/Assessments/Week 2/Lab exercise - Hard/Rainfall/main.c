#include <stdio.h>

int main()
{
    int r[12], rAvg, rTot = 0, rMin, rMax, i, rMinMonth = 1, rMaxMonth = 1;
    bool invalid = false;
    for (i = 0; i < 12; i++)
    {
        scanf("%d", &r[i]);

        if (r[i] < 0)
        { // Check for invalid input
            invalid = true;
            break;
        }

        if (i == 0)
        {
            rMin = r[i];
            rMax = r[i];
        }

        if (r[i] > rMax)
        {
            rMax = r[i];
            rMaxMonth = i + 1;
        }

        if (r[i] < rMin)
        {
            rMin = r[i];
            rMinMonth = i + 1;
        }

        rTot += r[i];
    }

    rAvg = rTot / 12;

    if (invalid)
        printf("Invalid input");
    else
        printf("Total rainfall : %d\nAverage rainfall : %d\nLowest rainfall month : %d\nHighest rainfall month: %d", rTot, rAvg, rMinMonth, rMaxMonth);
}