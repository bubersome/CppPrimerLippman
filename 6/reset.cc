// 6.2


#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

// function that takes a reference to an int 
// and sets the given object to zero
// i is just another name for the object passed to reset
void resetAddress(int &i) //take address or argument name
{
    i = 0;  // changes the value of the object to which i refers
}

// function that takes a pointer 
// and sets the pointed-to value to zero
void resetPointer(int *ip) //take pointer
{
    *ip = 0;  // changes the value of the object to which ip points
    ip = 0;   // changes the local copy of ip; the argument is unchanged
}

void swap(int &v1, int &v2){  // if the values are already the same, no need to swap, just return
    if (v1 == v2)
        return;  // if we're here, there's work to do
    int tmp = v2;
    v2 = v1;
    v1 = tmp;  // no explicit return necessary
}


int main() 
{
    int n = 0, i = 41;
    int &r = n;      // r is bound to n (i.e., r is another name for n)
    r = 42;        // n is now 42
    r = i;        // n now has the same value as i
    i = r;        // i has the same value as n

	int j = 42;
	resetAddress(j);  // j is passed by reference; the value in j is changed
	cout << "j = " << j  << endl;  // prints j = 0

	j = 42;    // restore the original value of j
	resetPointer(&j);                     // changes j but not the address of j
	cout << "j = "  << j << endl;  // prints j = 0

	j = 42;    // restore the original value of j
	int *p = &j;
	resetPointer(p); // changes object to which p points not the address in p
	cout << "j = "  << *p << endl;  // prints j = 0

    return 0;
}
