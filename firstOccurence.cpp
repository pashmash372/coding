#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int ele, int size)
{
    int start = 0;
    int end = size - 1;
    int mid, res = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ele == arr[mid])
        {
            res = mid;
            end = mid - 1;
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
    return res;
}
int main()
{

    int arr[] = {2, 4, 10, 10, 10, 20};
    int ele = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    int pos = firstOccurence(arr, ele, size);
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