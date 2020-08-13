#include <bits/stdc++.h>
using namespace std;

int countOfSubsetSum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                t[i][j] = 1;
            }
            else if (i == 0)
                t[i][j] = 0;
            else if (j == 0)
                t[i][j] = t[i - 1][j];
            else if (arr[i - 1] <= sum)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    int arr[] = {1, 1,1,1};
    int sum = 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countOfSubsetSum(arr, sum, n);
    return 0;
}