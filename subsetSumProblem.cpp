#include <bits/stdc++.h>
using namespace std;
int subSetSum(int W, int wt[], int n)
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
int main()
{

    int wt[] = {3, 34, 4, 12, 5, 2};
    int W = 9;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout<<subSetSum(W, wt, n);
    return 0;
}