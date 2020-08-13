#include <bits/stdc++.h>
using namespace std;
#define loop(x, n) for (int x = 0; x < n; ++x)
bool subSetSum(int W, int wt[], int n)
{

    bool t[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= W; i++)
        t[0][i] = false;

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            if (wt[i - 1] <= W)
            {
                t[i][j] = t[i - 1][j - wt[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }   
        }
    }
    loop(i, n+1)
    {
        loop(j, W+1)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][W];
}
int main()
{

    int wt[] = {1, 2, 7};
    int W = 10;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << subSetSum(W, wt, n);
    return 0;
}