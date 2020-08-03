#include <bits/stdc++.h>
using namespace std;

int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y=y>>1; // y =y/2
        x=x*x; 
    }
    return res;
}

int main()
{
    int x = 2;
    unsigned int y = 4;

    cout << power(x, y);
    return 0;
}