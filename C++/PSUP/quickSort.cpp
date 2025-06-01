#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int findPartitionIndex(int arr[], int lo, int hi)
{
    int i = lo;
    int j = hi;
    int pivotElement = arr[lo];
    while (i < j)
    {
        while (arr[i] <= pivotElement)
            i++;
        while (arr[j] > pivotElement)
            j--;
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, j, lo);
    return j;
}

void quickSort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int partitionIndex = findPartitionIndex(arr, lo, hi);
        quickSort(arr, lo, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, hi);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}