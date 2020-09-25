#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)

int lcs(char X[], char Y[], int m, int n)
{
    int t[m + 1][n + 1];

    loop_0(i, m + 1)
        t[i][0] = 0;
    loop_0(i, n + 1)
        t[0][i] = 0;
    loop(i, 1, m + 1)
    {
        loop(j, 1, n + 1)
        {
            if (X[i - 1] == Y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(
                    t[i - 1][j],
                    t[i][j - 1]);
            }
        }
    }
    return t[m][n];
}
bool patternMatching(char X[], char Y[], int m, int n)
{
    int l = lcs(X, Y, m, n);
    int minlength = min(m, n);
    if (minlength == l)
        return true;
    else
        return false;
}

int main()
{
    char X[] = "AXY";
    char Y[] = "ADXCPY";

    int m = strlen(X);
    int n = strlen(Y);

    cout << patternMatching(X, Y, m, n);

    return 0;
}