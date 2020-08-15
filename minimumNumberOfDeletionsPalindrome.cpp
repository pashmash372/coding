#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)
void swap(char &x, char &y)
{
    char temp = x;
    x = y;
    y = temp;
}
char *reverseString(char const *str)
{

    int n = strlen(str);

    char *rev = new char[n + 1];
    strcpy(rev, str);
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        swap(rev[i], rev[j]);
        i++;
        j--;
    }    
    return rev;
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
    return t[m][n];
}
int minimumNumberOfDeletions(char X[],  int m)
{
    char * Y =reverseString(X);
    // cout<<"Y="<<Y<<endl;
    int n=strlen(Y);
    return m-lcs(X, Y, m, n);
}

int main()
{
    char X[] = "geeksforgeeks";
    // loop(i,0,)

    int m = strlen(X);  
    int l=minimumNumberOfDeletions(X, m);
    cout<<"Minimum number of deletions = "<<l<<endl;

    return 0;
}