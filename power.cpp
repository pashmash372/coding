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

int main()
{
    int x = 2;
    unsigned int y = -1;

    cout << power(x, y);
    return 0;
}