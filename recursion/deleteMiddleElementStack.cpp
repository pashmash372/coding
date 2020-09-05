#include <bits/stdc++.h>
using namespace std;


void printStack(stack <int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
void solve(stack <int>&s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
    return;
}
stack<int> midDel(stack<int>& s){
    if(s.size()==0){
        return s;
    }
    int k=s.size()/2+1;
    solve(s,k);
    return s;
}
int main(){
    stack <int> s;
    int arr []={1,2,3,4,5};
    for (int i:arr)
        s.push(i);
    midDel(s);
    printStack(s);
    return 0;
}