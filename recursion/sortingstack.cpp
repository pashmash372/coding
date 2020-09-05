#include<bits/stdc++.h>
using namespace std;

void printStack(stack <int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
void insert(stack <int> &s,int temp){
    if (s.size()==0 ||s.top() >=temp){
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}
void sortStack(stack <int> &s){
    if(s.size()==1)
    return;
    int temp=s.top();
    s.pop();
    sortStack(s);
    insert(s,temp);
}
int main(){
    stack <int> s;
    int arr []={1,2,3,4,5,6,43,22,1};
    for (int i:arr)
        s.push(i);
    sortStack(s);
    printStack(s);
    return 0;
}