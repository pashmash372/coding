#include <bits/stdc++.h>
using namespace std; 

void insert(vector <int>&v ,int temp){
    if(v.size()==0 || v[v.size()-1] <=temp){
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return;
}
void sort (vector<int>&v){
    if(v.size()==1)
    return ;
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp); 
}
int main(){
    cout<<"Hello world ";
    vector <int> v; 
    v={5 ,4 ,3, 2, 1 ,8,7,23,4574,12} ;
    sort(v);
   for (int i :v)
       cout<<i<<" "; 
    return 0;
}