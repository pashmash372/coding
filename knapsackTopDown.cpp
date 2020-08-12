
#include <bits/stdc++.h>
using namespace std;

int knapSackRec(int W, int wt[], int val[],
                int n, int **dp)
{

    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n] > W)
    {

        // Store the value of function call
        // stack in table before return
        dp[n][W] = knapSackRec(
            W, wt, val, n - 1, dp);
        return dp[n][W];
    }
    else
    {

        // Store value in a table before return
        dp[n][W] = max(
            val[n] + knapSackRec(
                         W - wt[n], wt, val, n - 1, dp),
            knapSackRec(W, wt, val, n - 1, dp));

        // Return value of table after storing
        return dp[n][W];
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    // double pointer to declare the
    // table dynamically
    int **dp;
    dp = new int *[n];

    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
    // memset(dp, -1, sizeof dp);

    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
    int val[] = {10, 20, 30};
    int wt[] = {1, 1, 1};
    int W = 2;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
