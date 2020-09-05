#include <bits/stdc++.h>
using namespace std;

int cielBinarySearch(int arr[], int ele, int size)
{
    int start = 0;
    int end = size - 1;
    int mid, res;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ele == arr[mid])
        {
            return arr[mid];
        }
        else if (ele < arr[mid])
        {
            res = arr[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
int main()
{

    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int ele = 5;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << cielBinarySearch(arr, ele, size) << endl;

    return 0;
}
