#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

priority_queue<piii> maxh;

vector<pii> v;
void kCloseOrigin(int *arr, int m, int n, int k)
{
    int x, y;
    int dist;
    for (int i = 0; i < m; i++)
    {
        x = *(arr + i * n + 0);
        y = *(arr + i * n + 1);

        dist = sqrt(x * x + y * y);
        maxh.push(make_pair(dist, make_pair(x, y)));
        while (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    while (maxh.size() > 0)
    {
        auto i = maxh.top();
        auto j = i.second;
        v.push_back(make_pair(j.first, j.second));
        maxh.pop();
    }
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second<<endl;
    }
    cout << endl;
}
int main()
{
    int arr[4][2] = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}};
    int k = 2;
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(arr[0]) / sizeof(arr[0][0]);

    kCloseOrigin((int *)arr, m, n, k);
    return 0;
}