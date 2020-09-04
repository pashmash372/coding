#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n, int k, int mx)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mx)
        {
            student++;
            sum = arr[i];
        }
        if (student > k)
        {
            return false;
        }
    }
    return true;
}

void solve(int arr[], int k, int size)
{
    //*max_element find the max element in array
    int start = *max_element(arr, arr + size);
    // accumulate gives the sum of arr or vector
    int end = accumulate(arr, arr + size, 0);

    int res = -1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isValid(arr, size, k, mid) == true)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << res;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int k = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    solve(arr, k, size);
    return 0;
}