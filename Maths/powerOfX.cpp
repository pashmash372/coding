// Iterative C++ program to compute modular power
#include <iostream>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x,  int y)
{
    int res = 1; // Initialize result

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x);

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x);
    }
    return res;
}

// Driver code
 int main()
{
    int x = 2;
    int y = 10;
    cout << "Power is " << power(x, y);
    return 0;
}

// This code is contributed by shubhamsingh10
