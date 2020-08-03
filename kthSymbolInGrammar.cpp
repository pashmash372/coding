#include <bits/stdc++.h>
using namespace std;

int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
    {
        int k = power(x, y / 2);
        return k * k;
    }
    else
    {
        int k = power(x, y / 2);
        return x * k * k;
    }
}
int solve(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;
    int mid = power(2, n - 1) / 2;
    if (k <= mid)
        return solve(n - 1, k);
    else
        return !solve(n - 1, k - mid);
}
int main()
{
    int n = 4;
    int k = 8;
    cout << solve(n, k);
    return 0;
}