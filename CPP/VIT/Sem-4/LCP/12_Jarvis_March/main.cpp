#include <iostream>
using namespace std;

const int MAXN = 1000;

struct Point
{
    int x;
    int y;
};

long long sqDist(const Point &a, const Point &b)
{
    long long dx = (long long)a.x - b.x;
    long long dy = (long long)a.y - b.y;
    return dx * dx + dy * dy;
}

int orientation(const Point &a, const Point &b, const Point &c)
{
    long long val = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : -1;
}

int removeDuplicates(Point arr[], int n)
{
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        bool seen = false;
        for (int j = 0; j < m; j++)
        {
            if (arr[i].x == arr[j].x && arr[i].y == arr[j].y)
            {
                seen = true;
                break;
            }
        }

        if (!seen)
            arr[m++] = arr[i];
    }

    return m;
}

int main()
{
    int n;
    if (!(cin >> n) || n <= 0 || n > MAXN)
    {
        cout << "Convex Hull Size: 0\n";
        return 0;
    }

    Point pts[MAXN];
    for (int i = 0; i < n; i++)
    {
        if (!(cin >> pts[i].x >> pts[i].y))
        {
            cout << "Convex Hull Size: 0\n";
            return 0;
        }
    }

    n = removeDuplicates(pts, n);
    if (n == 0)
    {
        cout << "Convex Hull Size: 0\n";
        return 0;
    }

    if (n == 1)
    {
        cout << "Convex Hull Size: 1\n";
        cout << pts[0].x << " " << pts[0].y << "\n";
        return 0;
    }

    int leftMost = 0;
    for (int i = 1; i < n; i++)
    {
        if (pts[i].x < pts[leftMost].x || (pts[i].x == pts[leftMost].x && pts[i].y < pts[leftMost].y))
            leftMost = i;
    }

    int hull[MAXN];
    int hSize = 0;

    int p = leftMost;

    cout << "Jarvis March Steps:\n";

    int safety = 0;
    do
    {
        hull[hSize++] = p;

        int q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            int o = orientation(pts[p], pts[q], pts[i]);
            if (o == 1)
            {
                q = i;
            }
            else if (o == 0)
            {
                if (sqDist(pts[p], pts[i]) > sqDist(pts[p], pts[q]))
                    q = i;
            }
        }

        cout << "FROM " << pts[p].x << " " << pts[p].y << " TO " << pts[q].x << " " << pts[q].y << "\n";
        p = q;
        safety++;

    } while (p != leftMost && safety <= n + 1);

    cout << "Convex Hull Size: " << hSize << "\n";
    for (int i = 0; i < hSize; i++)
        cout << pts[hull[i]].x << " " << pts[hull[i]].y << "\n";

    return 0;
}
