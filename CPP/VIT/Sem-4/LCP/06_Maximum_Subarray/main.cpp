#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long max_sum = a[0];
    long long current_sum = a[0];

    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < n; i++)
    {
        if (current_sum + a[i] < a[i])
        {
            current_sum = a[i];
            temp_start = i;
        }
        else
        {
            current_sum += a[i];
        }

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    cout << max_sum << endl;
    cout << start << " " << end << endl;

    return 0;
}