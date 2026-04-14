#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

Point p0;

void swapPoint(Point &a, Point &b)
{
    Point temp = a;
    a = b;
    b = temp;
}

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

bool comesBefore(const Point &a, const Point &b)
{
    int o = orientation(p0, a, b);
    if (o == 0)
    {
        return distSq(p0, a) < distSq(p0, b);
    }
    return (o == 2);
}

void sortByPolar(Point *points, int n)
{
    // Simple bubble sort to avoid using <algorithm>.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (!comesBefore(points[j], points[j + 1]))
            {
                swapPoint(points[j], points[j + 1]);
            }
        }
    }
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

    // Step 1: Find bottom-most (and left-most in tie) point.
    int minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < points[minIdx].y ||
            (points[i].y == points[minIdx].y && points[i].x < points[minIdx].x))
        {
            minIdx = i;
        }
    }
    swapPoint(points[0], points[minIdx]);
    p0 = points[0];

    // Step 2: Sort by polar angle around p0.
    sortByPolar(points + 1, n - 1);

    // Step 3: Build hull using a stack-like array.
    Point *hull = new Point[n + 1];
    int top = 0;
    hull[top++] = points[0];
    hull[top++] = points[1];

    for (int i = 2; i < n; i++)
    {
        while (top >= 2 && orientation(hull[top - 2], hull[top - 1], points[i]) != 2)
        {
            top--;
        }
        hull[top++] = points[i];
    }

    cout << "Convex Hull Points (counterclockwise):\n";
    for (int i = 0; i < top; i++)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }

    delete[] points;
    delete[] hull;
    return 0;
}
