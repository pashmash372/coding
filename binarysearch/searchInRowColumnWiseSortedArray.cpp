#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int key, int m, int n)
{
    int i = 0, j = n - 1;
    while (i >= 0 && i < m && j >= 0 && j < n)
    {

        if (*(arr + i * m + j) == key)
        {
            break;
        }
        else if (*(arr + i * m + j) > key)
        {
            j--;
        }
        else if (*(arr + i * m + j) < key)
        {
            i++;
        }
    }
    if (i >= 0 && j >= 0)
        cout << i << " " << j << " " << *(arr + i * n + j) << endl;
    else
        cout << i << " " << j << " "  << "NOT FOUND" << endl;
}
int main()
{
    int arr[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    solve((int *)arr, 29, 4, 4);

    return 0;
}