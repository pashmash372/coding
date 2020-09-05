#include <bits/stdc++.h>
using namespace std;
vector<int> v;

typedef pair<int, int> pii;
priority_queue<pair<int,int>> maxh;
// priority_queue<pair<int, int> > pq; 

void kClose(int arr[], int size, int k, int x)
{
    for (int i = 0; i < size; i++)
    {

        maxh.push(make_pair(abs(x - arr[i]), arr[i]));
        if (maxh.size() > k)
        {
            // v.push_back(maxh.top().second);
            maxh.pop();
        }
    }
    while (maxh.size() > 0)
    {
        v.push_back(maxh.top().second);
        maxh.pop();
    }
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int x = 7;
    kClose(arr, size, k, x);
    return 0;
}