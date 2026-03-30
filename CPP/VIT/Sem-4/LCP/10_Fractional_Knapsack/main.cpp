#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    double W;

    cin >> n >> W;

    double weight[100], value[100], ratio[100];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
        ratio[i] = value[i] / weight[i];
    }

    // selection sort by ratio (descending)
    for (int i = 0; i < n; i++)
    {
        int best = i;

        for (int j = i + 1; j < n; j++)
        {
            if (ratio[j] > ratio[best])
                best = j;
        }

        if (best != i)
        {
            double t;

            t = ratio[i];
            ratio[i] = ratio[best];
            ratio[best] = t;

            t = weight[i];
            weight[i] = weight[best];
            weight[best] = t;

            t = value[i];
            value[i] = value[best];
            value[best] = t;
        }
    }

    double total = 0;

    for (int i = 0; i < n && W > 0; i++)
    {
        if (weight[i] <= W)
        {
            total += value[i];
            W -= weight[i];
        }
        else
        {
            total += value[i] * (W / weight[i]);
            W = 0;
        }
    }

    printf("%.4f\n", total);

    return 0;
}