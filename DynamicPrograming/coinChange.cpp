#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)
int coinchange(int W, int arr[], int n)
{
    int t[n + 1][W + 1];
    loop_0(i, W + 1)
    {
        t[0][i] = 0;
    }
    loop_0(i, n + 1)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i][j - arr[i - 1]]+ t[i - 1][j];
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
    int W = 10 ;
    int arr[] = {2, 5, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << coinchange(W, arr, n);

    return 0;
}