#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minh;
void connectRopes(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        minh.push(arr[i]);
    }
    int first, second,cost=0;
    while (minh.size() >=2)
    {
        first = minh.top();
        minh.pop();
        second = minh.top();
        minh.pop();
        cost=first+second;
        minh.push(cost);
    }
    cout<<cost;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    connectRopes(arr, size);
    return 0;
}
