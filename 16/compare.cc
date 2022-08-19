

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstring>
using std::strcmp;

#include <iostream>
using std::cout; using std::endl;

#include "compare.h"

int main()
{
    // instantiates int compare(const int&, const int&)
    cout << compare(1, 0) << endl;       // T is int

    // instantiates int compare(const vector<int>&, const vector<int>&)
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl; // T is vector<int>

    long l1, l2;
    int i1=16, i2;
    cout << compare(i1, i2)<< endl;      // instantiate compare(int, int)
    cout << compare(l1, l2)<< endl;      // instantiate compare(long, long)
    cout << compare<int>(i1, l2)<< endl; // uses compare(int, int)
    cout << compare<long>(i1, l2)<< endl;// uses compare(long, long)

    const char *cp1 = "hi", *cp2 = "world";
    cout << compare(cp1, cp2)<< endl;          // calls the specialization
    cout << compare<string>(cp1, cp2)<< endl;  // converts arguments to string

    return 0;
}

