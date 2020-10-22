#include <bits/stdc++.h>
#define loop(x, n) for (int x = 0; x < n; ++x)

using namespace std;

int minimumSubsetDifference(int arr[], int sum, int n)
{

    bool t[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= sum; i++)
        t[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {

            if (arr[i - 1] <= sum)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    vector<int> lastRow;
    // print the 2d array
    // loop(i, n + 1)
    // {
    //     loop(j, sum + 1)
    //     {
    //         cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int j = 0; j <= sum / 2; j++)
    {
        if (t[n][j] == true)
        {
            lastRow.push_back(j);
        }
    }

    int min = INT_MAX;
    int range = sum;
    int diff;
    for (int i = 0; i < lastRow.size(); i++)
    {
        diff = range - (2 * lastRow[i]);
        if (min > diff)
            min = diff;
    }

    return min;
}
int main()
{
    // int arr[] = {1, 6, 11, 5};
    int arr[] = {1,2,7};


    int range = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort(arr, arr + n);
    // cout<<"Sorted array ";

    // loop(i,n)
    // {
    //     cout << arr[i]<<" ";
    // }
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }

    cout << minimumSubsetDifference(arr, range, n);
    return 0;
}