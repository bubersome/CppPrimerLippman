
//
#include <iostream>
using std::cout; using std::endl;

// declarations of our factorial functions
// definitions are in LocalMath.cc
//#include "LocalMath.h"


int gcd(int v1, int v2)
{
    while (v2) {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;
    }
    return v1;
}


// factorial of val is ret = val * (val - 1) *  (val - 2) . . . * ((val -  (val - 1)) * 1)
int fact(int val)
{
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1)
        ret *= val--;  // assign ret * val to ret and decrement val
    return ret;        // return the result
}

// recursive version of factorial:
// calculate val!, which is  val * ... *3 *2 *1
// return 1
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}




int main()
{
	cout << factorial(5) << endl;
	cout << fact(5) << endl;
	cout << factorial(0) << endl;
	cout << fact(0) << endl;

	return 0;
}

