#include <iostream>
using namespace std;

void merge(int arr[], int mid, int lo, int hi)
{
    int l1 = mid - lo + 1;
    int l2 = hi - mid;

    int leftPart[l1];
    int rightPart[l2];

    for (int i = 0; i < l1; i++)
    {
        leftPart[i] = arr[lo + i];
    }
    for (int i = 0; i < l2; i++)
    {
        rightPart[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = lo;
    while (i < l1 && j < l2)
    {
        if (leftPart[i] <= rightPart[j])
        {
            arr[k] = leftPart[i];
            i++;
        }
        else
        {
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }
    while (i < l1)
    {
        arr[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < l2)
    {
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        merge(arr, mid, lo, hi);
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
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}