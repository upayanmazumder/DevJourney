#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

long long distSq(const Point &a, const Point &b)
{
    long long dx = (long long)a.x - b.x;
    long long dy = (long long)a.y - b.y;
    return dx * dx + dy * dy;
}

// Returns: 0 -> collinear, 1 -> clockwise, 2 -> counterclockwise
int orientation(const Point &a, const Point &b, const Point &c)
{
    long long val = ((long long)b.y - a.y) * ((long long)c.x - b.x) -
                    ((long long)b.x - a.x) * ((long long)c.y - b.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    if (n < 3)
    {
        cout << "Convex hull not possible (need at least 3 points).\n";
        return 0;
    }

    Point *points = new Point[n];
    cout << "Enter points as x y:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    // Find leftmost point.
    int left = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[left].x ||
            (points[i].x == points[left].x && points[i].y < points[left].y))
        {
            left = i;
        }
    }

    int *hullIndex = new int[n + 1];
    int hullSize = 0;

    int p = left;
    do
    {
        hullIndex[hullSize++] = p;
        int q = (p + 1) % n;

        for (int i = 0; i < n; i++)
        {
            int o = orientation(points[p], points[i], points[q]);

            // Take most counterclockwise point.
            if (o == 2)
            {
                q = i;
            }

            // If collinear, keep farthest one.
            if (o == 0 && distSq(points[p], points[i]) > distSq(points[p], points[q]))
            {
                q = i;
            }
        }

        p = q;
    } while (p != left);

    cout << "Convex Hull Points (counterclockwise):\n";
    for (int i = 0; i < hullSize; i++)
    {
        int idx = hullIndex[i];
        cout << "(" << points[idx].x << ", " << points[idx].y << ")\n";
    }

    delete[] points;
    delete[] hullIndex;
    return 0;
}
