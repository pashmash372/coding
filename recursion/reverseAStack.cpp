#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int ele = s.top();
    s.pop();
    insert(s, temp);
    s.push(ele);
}
void reverse(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    stack<int> s;
    for (int i : arr)
    {        
        s.push(i);
    }
    reverse(s);
    while (s.empty() != 1)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}