#include <bits/stdc++.h>
using namespace std;

vector<int> v;
stack<pair<int, int>> s;
vector<int> op;

void nglwithpair(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }

        s.push(make_pair(arr[i], i));
    }
}
void stockSpan(int arr[], int size)
{
    nglwithpair(arr, size);
    for (int i = 0; i < v.size(); i++)
    {
        op.push_back (i - v[i]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << op[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    stockSpan(arr, size);
    return 0;
}