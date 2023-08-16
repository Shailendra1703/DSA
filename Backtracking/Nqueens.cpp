#include <iostream>
using namespace std;
int count = 0;

bool isSafe(int **arr, int x, int y, int n)
{
    // for column

    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
            return false;
    }

    int row = x;
    int col = y;

    // left up diagonal
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = x;
    col = y;

    // right up diagonal
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;

        row--;
        col++;
    }

    return true;
}

void printSolution(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
    cout << endl
         << endl;
}
void nqueen(int **arr, int x, int n)
{
    if (x == n)
    {
        printSolution(arr, n);
        count++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            // if (nqueen(arr, x + 1, n))
            nqueen(arr, x + 1, n);

            arr[x][col] = 0; // backtrack
        }
    }

    return;
}
int main()
{
    int n;
    cout << "Enter No. of queens : ";
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }

    nqueen(arr, 0, n);

    cout << "Total solutions are : " << count;

    return 0;
}