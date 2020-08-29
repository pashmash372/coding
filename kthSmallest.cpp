#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxh;
void maxheap(int arr[], int size, int k)
{

    for (int i = 0; i < size; i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    cout<< maxh.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    maxheap(arr, size, k);
    return 0;
}