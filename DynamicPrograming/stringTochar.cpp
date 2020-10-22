#include <bits/stdc++.h>

using namespace std;
int main()
{
    // string a = "abhilash";
    // cout << a << endl;
    // cout << a[4];
    // cout << a.length();
    // string b = a;
    // cout << b << endl;
    // reverse(b.begin(), b.end());
    // cout << b << endl;

    // cout << "testing for loop";
    // cout << endl;
    // for (int i = 0; i < a.length(); i++)
    // {
    //     cout << a[i] << "\n";
    // }
    unordered_map<char,int> mp;
    string s ="abbabde";
    int i=s.length()-1;
    while(i>=0){
        mp[s[i]]++;
        // cout<<s[i]<<endl;
        i--;
    }
    return 0;
}