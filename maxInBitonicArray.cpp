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
                return arr[mid];
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
                return 0;
            else
                return 1;
        }
        else if (mid == size - 1)
        {
            if (arr[size - 1] > arr[size - 2])
            {
                return size - 1;
            }
            else
            {
                return size - 2;
            }
        }
    }
    return -1;
}
int main()
{
    // this is based on binary search on answer in these array is not sorted
    // you come up to determine bs usage here when you use  mid ans ,right-left criteria concept
    int arr[] = {5, 10, 20, 30,40,19,15};
    // int arr[] = {1,1,1,1,1,1,1,2,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<peakEle(arr, size)<<endl;

    return 0;
}