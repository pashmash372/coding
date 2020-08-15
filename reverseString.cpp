#include <bits/stdc++.h>
using namespace std;
#define loop_0(x, n) for (int x = 0; x < n; x++)
#define loop(x, i, n) for (int x = i; x < n; x++)

void swap(char& x, char& y)
{
    char temp = x;
    x = y;
    y = temp;
}
char *reverseString(char const *str)
{

    int n = strlen(str);

    char *rev = new char[n+1];
    strcpy(rev,str);
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        swap(rev[i], rev[j]);
        i++;
        j--;
    }
    cout<<rev<<endl;
    return rev;
}

int main()
{
    const char *X = "PASHMASH";
    const char *Y = reverseString(X);
    cout<<X<<endl;
    cout<<Y<<endl;

    return 0;
}