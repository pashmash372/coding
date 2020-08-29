#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minh;
vector<int> v;
void minheap(int arr[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            v.push_back(minh.top());
            minh.pop();
        }
    }
    while (minh.size() >0)
    {
        v.push_back(minh.top());
        minh.pop();
    }
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    minheap(arr, size, k);

    return 0;
}