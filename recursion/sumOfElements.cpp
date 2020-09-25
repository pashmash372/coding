#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxh;
int kThSmallest(int arr[], int size, int k)
{
    int ans;
    for (int i = 0; i < size; i++)
    {
        maxh.push(arr[i]);
        while (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    ans = maxh.top();
    while (maxh.size() > 0)
    {
        maxh.pop();
    }
    return ans;
}
int main()
{
    int arr[] = {1, 3, 12, 5, 15, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k1 = 3;
    int k2 = 6;
    int first = kThSmallest(arr, size, k1);
    int second = kThSmallest(arr, size, k2);
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > first && arr[i] < second)
        {
            sum += arr[i];
        }
    }
    cout << sum;
    return 0;
}