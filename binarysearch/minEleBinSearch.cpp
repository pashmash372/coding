#include <bits/stdc++.h>
using namespace std;

int minEle(int arr[], int size, int ele)
{
    int l = 0;
    int h = size - 1;
    int mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (arr[mid] == ele)
        {
            return arr[mid]-ele;
        }
        else if (arr[mid] < ele)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return min(abs(arr[l] - ele), abs(arr[h] - ele));
}

int main()
{
    int arr[] = {1, 3, 8, 10,12, 15};
    int ele = 16;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<minEle(arr, size, ele);
    return 0;
}