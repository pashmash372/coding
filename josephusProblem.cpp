#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    solve(v, k, index, ans);
}
int main()
{
    int n = 14;
    int k = 2;
    int ans = 0;
    int index = 0;
    vector<int> v;
    for (int i = 1; i < n; i++)
    {
        v.push_back(i);
    }
    // k--;

    solve(v, k, index, ans);
    cout<<ans;
    return 0;
}