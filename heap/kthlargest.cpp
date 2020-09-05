#include <bits/stdc++.h>    
using namespace std;

// priority_queue<int> minh;
priority_queue<int,vector<int>,greater<int>> minh;
void minheap(int arr[], int size, int k)
{

    for (int i = 0; i < size; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    cout<< minh.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15,100,200,300};
    //{3,4,7,10,15,20}
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    minheap(arr, size, k);
    return 0;
}