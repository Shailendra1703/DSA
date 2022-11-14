#include <iostream>
#include <time.h>
using namespace std;

int partion(int arr[], int i, int j)
{
    int pivot = i;

    while (i < j)
    {
        while (arr[i] <= arr[pivot])
            i++;

        while (arr[j] > arr[pivot])
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivot]);
    return j;
}

void quickSort(int arr[], int i, int j)
{
    int pivot = j;
    while (i < pivot)
    {
        pivot = partion(arr, i, j);
        quickSort(arr, i, pivot - 1);
        quickSort(arr, pivot + 1, j);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand();

    cout << "BEFORE" << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    
    int l = clock();
    cout << "\n\nstart time " << l << endl;
    quickSort(arr, 0, n - 1);

    int k = clock();
    cout << "\n\nEnd time " << k << endl;

    cout << "Total time " << k - l << endl;

    cout << "\n\nAFTER" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}