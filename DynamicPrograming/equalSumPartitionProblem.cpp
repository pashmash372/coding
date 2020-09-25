#include <bits/stdc++.h>
using namespace std;
bool equalSumPartitionImpl(int W, int wt[], int n)
{
    bool t[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
            else if (wt[i - 1] <= W)
            {
                t[i][j] = t[i - 1][j - wt[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}
bool equalSumPartition(int wt[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }
    if (sum % 2 != 0)
        return false;

    return equalSumPartitionImpl(sum / 2, wt, n);
}
int main()
{

    int wt[] = {1, 5, 11, 5};
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << equalSumPartition(wt, n);
    return 0;
}