#include <bits/stdc++.h>
using namespace std;

int static ct = 0;
int minOperations(string A, string B, int target)
{
    if (A.length() > target || B.length() > target)
    {
        return ct;
    }
    string temp;
    temp += B;
    temp += A;
    ct++;
    return minOperations(temp, A, target);
}

int main()
{
    string A;
    // A = "so";
    A="dog";
    string B;
    // B = "easy";
    B="go";
    int target;
    // target = 100;
    target=5;
    int result;
    result = minOperations(B, A, target);
    cout << result;
    return 0;
}