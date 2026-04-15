#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_N = 100;
const int INF = 1000000000;

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partitionArray(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swapInt(arr[i], arr[j]);
        }
    }

    swapInt(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high)
{
    int pivotIndex = low + (rand() % (high - low + 1));
    swapInt(arr[pivotIndex], arr[high]);
    return partitionArray(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, p - 1);
        randomizedQuickSort(arr, p + 1, high);
    }
}

void runQuickSort()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > MAX_N)
    {
        cout << "Invalid size. Max allowed is " << MAX_N << ".\n";
        return;
    }

    int arr[MAX_N];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void runAllPairsShortestPath()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > MAX_N)
    {
        cout << "Invalid number of vertices. Max allowed is " << MAX_N << ".\n";
        return;
    }

    int dist[MAX_N][MAX_N];

    cout << "Enter adjacency matrix (use " << INF << " for no direct edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall for all-pairs shortest paths.
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    int throughK = dist[i][k] + dist[k][j];
                    if (throughK < dist[i][j])
                    {
                        dist[i][j] = throughK;
                    }
                }
            }
        }
    }

    cout << "Shortest path matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] >= INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    srand((unsigned int)time(0));

    int choice;
    cout << "Choose option:\n";
    cout << "1. Randomized Quick Sort\n";
    cout << "2. All-Pairs Shortest Path (Floyd-Warshall)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        runQuickSort();
    }
    else if (choice == 2)
    {
        runAllPairsShortestPath();
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}
