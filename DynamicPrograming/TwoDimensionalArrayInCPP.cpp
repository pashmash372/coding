#include <iostream>
using namespace std;

void processArr(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(a + i * n + j);
        }
    }
}
int main()
{
    int n = 2;
    int arr[n][n];
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;

    processArr((int *)arr,n);
    return 0;
}