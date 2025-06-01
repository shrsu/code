#include <iostream>
using namespace std;

int main()
{
    // Enter your code below
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = findPos(arr, n);
    if (ans != -1)
    {
        cout << ans;
    }
    else
    {
        cout << "Invalid input";
    }
    return 0;
}