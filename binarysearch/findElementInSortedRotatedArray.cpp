#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int ele)
{
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ele == arr[mid])
        {
            return mid;
        }
        else if (ele < arr[mid])
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
int minElementRotated(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid, next, prev;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        next = (mid + 1) % size;
        prev = (mid - 1 + size) % size;
        if (arr[mid] < arr[prev] && arr[mid] < arr[end])
        {
            break;
        }
        else if (arr[start] <= arr[mid])
        {
            start = mid;
        }
        else if (arr[mid] <= arr[end])
        {
            end = mid;
        }
    }
    return mid;
}
int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ele = 8;
    int minIndex = minElementRotated(arr, size);    
    int first = binarySearch(arr, 0, minIndex - 1, ele);
    int second = binarySearch(arr, minIndex, size - 1, ele);
    if (first != -1 || second != -1)
    {
        int ans;
        if (first != -1)
        {
            ans = first;
        }
        else
        {
            ans=second;
        }
        cout<<ans<<endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }

    return 0;
}