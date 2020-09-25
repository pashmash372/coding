#include <bits/stdc++.h>
using namespace std;

int peakEle(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid > 0 && mid < size - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid - 1] > arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (arr[0] > arr[1])
            {
                return 0;
            }
            else if (arr[size - 1] > arr[size - 2])
            {
                return size - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 20, 21, 22, 421, 15, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = peakEle(arr, size);
    cout << ans;
    return 0;
}