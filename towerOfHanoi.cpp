#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int h, int n, int &count)
{
    count++;
    if (n == 1)
    {
        printf("Move plate %d from rod %d to rod %d\n", n, s, d);
        return;
    }
    solve(s, h, d, n - 1, count);
    printf("Move plate %d from rod %d to rod %d\n", n, s, d);
    solve(h, d, s, n - 1, count);
    return;
}
int main()
{
 
    int n = 4;
    int s = 1; // source
    int h = 2; // helper
    int d = 3; // destination
    int count = 0;
    solve(s, d, h, n, count);
    cout << endl;
    cout << "Count " << count;

    return 0;
}