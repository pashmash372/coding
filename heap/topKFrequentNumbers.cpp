#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> minh;
unordered_map<int, int> mp;
vector<pii> v;

void freq(int arr[], int k)
{
    for (auto i = mp.begin(); i != mp.end(); i++)
    {

        minh.push(make_pair(i->second, i->first));

        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    while (minh.size() > 0)
    {
        auto i = minh.top();

        v.push_back(make_pair(i.first, i.second));
        minh.pop();
    }
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second <<" "<< v[i].first << endl;
    }
    
}
int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    int k = 3;

    freq(arr, k);
    return 0;
}
