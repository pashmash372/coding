#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)

int lcs(char X[], char Y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (X[m - 1] == Y[n - 1])
    {
        return 1 + lcs(X, Y, m - 1, n - 1);
    }
    else
    {
        return max(
            lcs(X, Y, m - 1, n),
            lcs(X, Y, m, n - 1));
    }
}

int main()
{
    char X[] = "ABCDGH";
    char Y[] = "AEDFHR";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is " << lcs(X, Y, m, n);

    return 0;
}