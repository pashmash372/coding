#include <bits/stdc++.h>
using namespace std;

int floorBinarySearch(int arr[], int ele, int size)
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
            end = mid - 1;
        }
        else
        {
            res = arr[mid];
            start = mid + 1;
        }
    }
    return res;
}
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

    // int arr[]={4,6,10};
    // int key=7;
    int arr[] = {1,3,8,10,12,15};
    int key = 12;
    int size = sizeof(arr) / sizeof(arr[0]);
    int low= floorBinarySearch(arr, key, size);
    int high=cielBinarySearch(arr, key, size);
    cout<<low<<" "<<high<<endl;
    int ans=min(abs(low-key),abs(high-key));

    cout<<ans<<endl;

    return 0;
}
