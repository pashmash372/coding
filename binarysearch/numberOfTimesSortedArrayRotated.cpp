#include <bits/stdc++.h>
using namespace std;

int sortedRotatedArray(int arr[], int size)
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
    // int arr[] = {11, 12, 15, 18,19,202,2020,2342, 2, 5, 6, 8};
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    // int arr[] = {10, 18, 18, 20, 21, 21, 21, 1, 2};
    // int arr[] = {10, 18, 19, 4, 4, 4, 8, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sortedRotatedArray(arr, size) << endl;
    return 0;
}