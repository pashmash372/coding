#include <bits/stdc++.h>

using namespace std;
vector<string> vec;
void printVector(vector<string> vec)
{

    cout << "Vector: ";
    for (string x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
}
void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        // vec.push_back(op);
        cout << op << endl;
        return;
    }
    string op1 = op, op2 = op;
    op1.push_back('_');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
}
void permutationsWithSpace(string s)
{
    string op;
    op.push_back(s[0]); 
    s.erase(s.begin()+0);
    solve(s, op);
}
int main()
{
    string s = "abc";
    permutationsWithSpace(s);

    return 0;
}