#include <bits/stdc++.h>
using namespace std;

void printStack(stack <int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
void insert(stack <int> &s,int temp){
    if (s.size()==0 ){
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}
void reverse(stack <int> &s){
    if (s.size()==1)
    return ;
    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
    return;
    
}
int main(){
    stack <int> s;
    int arr []={1,2,3,4,5};
    for (int i:arr)
        s.push(i);
    reverse(s);
    printStack(s);
    return 0;
}