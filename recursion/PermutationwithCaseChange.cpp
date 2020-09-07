#include <bits/stdc++.h>

using namespace std;
void solve(string op,string ip){
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }
    string op1=op;
    string op2=op;
    
    op1.push_back(toupper(ip[0]));
    op2.push_back(tolower(ip[0]));

    ip.erase(ip.begin()+0);

    solve(op1,ip);
    solve(op2,ip);


}
void PermutationwithCaseChange(string s){
    string ip=s;
    string op="";
    solve(op,ip);
}

int main()
{
    string s = "ab";
    PermutationwithCaseChange(s);
    return 0;
}