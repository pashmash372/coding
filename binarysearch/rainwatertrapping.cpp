#include <bits/stdc++.h>
using namespace std;
vector<int> maxR;
vector<int> maxL;
void rainwatertrap(int arr[], int size)
{
    int t;
    for (int i = size - 1; i >= 0; i--)
    {
        if (i == size - 1)
        {
            maxR.push_back(-1);
            t = arr[i];
        }
        else
        {
            t = max(t, arr[i]);
            maxR.push_back(t);
        }
    }
    reverse(maxR.begin(), maxR.end());
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            maxL.push_back(-1);
            t = arr[i];
        }
        else
        {
            t = max(t, arr[i]);
            maxL.push_back(t);
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        int r = maxR[i];
        int l = maxL[i];
        if (r == -1 || l == -1)
            continue;
        sum += abs(min(r, l) - arr[i]);
    }
    cout << sum;
}
int main()
{
    // int arr[] = {3, 0, 0, 2, 0, 4};
    int arr[] ={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    rainwatertrap(arr, size);
    return 0;
}