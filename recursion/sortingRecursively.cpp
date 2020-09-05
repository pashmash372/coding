#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v[v.size() - 1];
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
    return;
}
void sort(vector<int> &v)
{
    if (v.size() == 1)
        return;
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v, temp);
}
int main()
{
    cout << "Hello world "<<endl;
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + size);
    for (int i : v)
        cout << i << " ";
    cout << endl;
    sort(v);
    for (int i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}