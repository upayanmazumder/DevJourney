#include <iostream>
using namespace std;

const int MAXN = 1000;

struct Point
{
    int x;
    int y;
};

Point p0;

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

bool polarLess(const Point &a, const Point &b)
{
    int o = orientation(p0, a, b);

    if (o == 0)
        return sqDist(p0, a) < sqDist(p0, b);

    return o == 1;
}

void selectionSortByPolar(Point arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int best = i;
        for (int j = i + 1; j < n; j++)
        {
            if (polarLess(arr[j], arr[best]))
                best = j;
        }

        if (best != i)
        {
            Point t = arr[i];
            arr[i] = arr[best];
            arr[best] = t;
        }
    }
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

    int pivot = 0;
    for (int i = 1; i < n; i++)
    {
        if (pts[i].y < pts[pivot].y || (pts[i].y == pts[pivot].y && pts[i].x < pts[pivot].x))
            pivot = i;
    }

    Point temp = pts[0];
    pts[0] = pts[pivot];
    pts[pivot] = temp;

    p0 = pts[0];

    if (n > 1)
        selectionSortByPolar(pts + 1, n - 1);

    Point filtered[MAXN];
    int m = 1;
    filtered[0] = pts[0];

    int i = 1;
    while (i < n)
    {
        int j = i;
        while (j + 1 < n && orientation(p0, pts[j], pts[j + 1]) == 0)
            j++;

        filtered[m++] = pts[j];
        i = j + 1;
    }

    if (m == 1)
    {
        cout << "Convex Hull Size: 1\n";
        cout << filtered[0].x << " " << filtered[0].y << "\n";
        return 0;
    }

    if (m == 2)
    {
        cout << "Convex Hull Size: 2\n";
        cout << filtered[0].x << " " << filtered[0].y << "\n";
        cout << filtered[1].x << " " << filtered[1].y << "\n";
        return 0;
    }

    Point st[MAXN];
    int top = 0;
    st[top++] = filtered[0];
    st[top++] = filtered[1];

    cout << "Graham Scan Steps:\n";
    cout << "PUSH " << filtered[0].x << " " << filtered[0].y << "\n";
    cout << "PUSH " << filtered[1].x << " " << filtered[1].y << "\n";
    for (int k = 2; k < m; k++)
    {
        while (top >= 2 && orientation(st[top - 2], st[top - 1], filtered[k]) <= 0)
        {
            cout << "POP " << st[top - 1].x << " " << st[top - 1].y << "\n";
            top--;
        }

        st[top++] = filtered[k];
        cout << "PUSH " << filtered[k].x << " " << filtered[k].y << "\n";
    }

    cout << "Convex Hull Size: " << top << "\n";
    for (int k = 0; k < top; k++)
        cout << st[k].x << " " << st[k].y << "\n";

    return 0;
}
