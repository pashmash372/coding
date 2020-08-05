#include <bits/stdc++.h>

using namespace std;
vector<string> str;
set <string> setStr;
void printVector(vector<string > vec) 
{ 
  
    cout << "Vector: "; 
    for (string  x : vec) { 
        cout << x << " "; 
    } 
    cout << endl; 
} 
void printSet(set<string > s) 
{ 
  
    cout << "Set: "; 
    for (string x : s) { 
        cout << x << " "; 
    } 
    cout << endl; 
}   
set <string > convertToSet(vector <string > v){
    set <string > s(v.begin(),v.end()); 
    return s;
}
void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        op==""? str.push_back("{}"):str.push_back(op);
        return;
    }    
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);
}

void printUniqueSubset(string s)
{
    string ip = s;
    string op = "";
    solve(ip, op);
}

int main()
{
    string s = "aac";
    printUniqueSubset(s);
    sort(str.begin(),str.end());
    printVector(str);
    convertToSet(str);
    printSet(convertToSet(str));
    
    return 0;
}