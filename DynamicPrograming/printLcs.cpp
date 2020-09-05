#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)

void printLCS(int m, int n, char X[], char Y[], int* t)
{
    int i = m, j = n;
    vector<char> result;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result.push_back(X[i-1]);
            i--;
            j--;
        }
        else if(*(t+(i-1)*(n+1)+j) > *(t+i*(n+1)+(j-1)))
        {
            i--;
        }
        else
        {
            j--;
        }        
    }
    reverse(result.begin(),result.end());
    loop_0(i,result.size())
        cout<<result[i];
}
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
    printLCS(m, n, X, Y, (int *)t);
    return t[m][n];
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