#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)
int unboundedKnapSack(int W, int wt[], int val[], int n)
{
    int t[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int W = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    cout << unboundedKnapSack(W, wt, val, n);

    return 0;
}