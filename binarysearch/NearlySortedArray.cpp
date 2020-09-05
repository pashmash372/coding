#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int ele, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ele == arr[mid])
        {
            return mid;
        }
        if (mid >= start && arr[mid - 1] == ele)
        {
            return mid - 1;
        }
        if (mid + 1 <= end && arr[mid + 1] == ele)
            return mid + 1;
        else if (ele < arr[mid])
        {
            end = mid - 2;
        }
        else
        {
            start = mid + 2;
        }
    }
    return -1;
}
int main()
{

    int arr[] = {5,10,30,20,40};
    int ele =  40;
    int size = sizeof(arr) / sizeof(arr[0]);
    int pos = binarySearch(arr, ele, size);
    if (pos != -1)
    {
        cout << pos;
    }
    else
    {
        cout << "not found";
    }
    return 0;
}