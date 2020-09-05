#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)
int cutRod(int price[],int n)
{

    int t[n + 1][n + 1];
    loop(i, 0, n + 1)
    {
        loop(j, 0, n + 1)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (i  <= j)
            {
                
                t[i][j] = max(price [i - 1] + t[i][j - i], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    loop_0(i, n+1)
    {
        loop_0(j, n+1)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][n];
}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length[] ={1,2,3,4,5,6,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<cutRod(arr,size);    
    return 0;
}