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
        else if (ele > arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{

    int arr[] = {20,17,15,14,13,12,10,9,8,4};
    int ele = 4;
    int size = sizeof(arr) / sizeof(arr[0]);
    int pos = binarySearch(arr, ele, size);
    if (pos != -1)
    {
        cout << pos;
    }
    else
    {
        cout << "not found"<<endl;
    }
    return 0;
}