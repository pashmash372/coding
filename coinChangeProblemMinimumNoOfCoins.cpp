#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)
int coinChangeProblemMinimumNoOfCoins(int W, int coins[], int n)
{
    int t[n + 1][W + 1];
    loop_0(i, n + 1)
        t[i][0] = 0;
    loop_0(i, W + 1)
        t[0][i] = INT_MAX - 1;
    loop(i, 1, W + 1)
        t[1][i] = i / coins[0];
    loop(i, 2, n + 1)
    {
        loop(j, 1, W + 1)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(
                    t[i][j - coins[i - 1]] +1,
                    t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
     loop_0(i,n+1){
        loop_0(j,W+1){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][W];
}
int main()
{
    int W = 30;
    int coins[] = {25, 10, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    sort(coins, coins + n);
    loop_0(i,n)
        cout<<coins[i]<<" ";
    cout<<endl;
    cout << coinChangeProblemMinimumNoOfCoins(W, coins, n);

    return 0;
}