// C++ program to demonstrate working of 
// extended Euclidean Algorithm 
#include <bits/stdc++.h> 
using namespace std; 

// Function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0; 
		*y = 1; 
		return b; 
	} 

	int x1, y1; // To store results of recursive call 
	int gcd = gcdExtended(b%a, a, &x1, &y1); 

	// Update x and y using results of 
	// recursive call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
} 

// Driver Code 
int main() 
{ 
	int x, y, a = 3, b =11; 
	int g = gcdExtended(a, b, &x, &y); 
	cout << "GCD(" << a << ", " << b 
		<< ") = " << g << endl; 
    cout<<x<< " "<<y;
    return 0;
} 

// This code is contributed by TusharSabhani 
