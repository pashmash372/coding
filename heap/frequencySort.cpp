#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> maxh;

unordered_map<int, int> mp;
vector<int> v;
void freqSort(int arr[], int size)
{
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxh.push(make_pair(i->second, i->first));
    }
    while (maxh.size() > 0)
    {
        auto i = maxh.top();
        maxh.pop();
        int freq = i.first;
        int ele = i.second;
        for (int i = 0; i < freq; i++)
        {
            v.push_back(ele);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4,5,5,5,5,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    freqSort(arr, size);
    return 0;
}