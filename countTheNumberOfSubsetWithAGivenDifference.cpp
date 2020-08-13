#include <bits/stdc++.h>
using namespace std;
#define loop(x,i,n) for(int x=i;x<n;x++)
#define loop_0(x,n) for(int x=0;x<n;x++)
int solve(int arr[],int sum,int n){
    int t[n+1][sum+1];
    loop(i,0,sum+1)
        t[0][i]=0;
    loop(i,0,n+1)
        t[i][0]=1;
    loop(i,1,n+1)
    {
         loop(j,1,sum+1)
        {

            if (arr[i - 1] <= sum)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    // loop_0(i,n+1){
    //     loop_0(j,sum+1){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return t[n][sum];
}

void countTheNumberOfSubsetWithAGivenDifference(int arr[],int diff,int n){
    int sigmaOfarr=0;
    loop(i,0,n){
        sigmaOfarr+=arr[i];
    }
    int s1=(sigmaOfarr+diff)/2;
    
    cout<<solve( arr, s1, n);
}
int main()
{
    int arr[] = {1,1,2,3};
    int diff =1;
    int n = sizeof(arr) / sizeof(arr[0]);
    countTheNumberOfSubsetWithAGivenDifference(arr, diff,n);
    return 0;
}
