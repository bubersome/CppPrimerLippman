

#include <iterator>
using std::begin; using std::end;

#include <list>
using std::list;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::endl; 

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <cstddef>
using std::size_t;

#include "Blob.h"

int main()
{
    Blob<int> ia;                // empty Blob<int>
	Blob<int> ia2 = {0,1,2,3,4}; // Blob<int> with five elements
	vector<int> v1(10, 0); // ten elements initialized to 0
    Blob<int> ia3(v1.begin(), v1.end());  // copy elements from v1
    cout << ia << "\n" << ia2 << "\n" << ia3 << endl;

    // these definitions instantiate two distinct Blob types
    Blob<string> names; // Blob that holds strings
    Blob<double> prices;// different element type

	// instantiates Blob<string> class and its
	//  initializer_list<const char*> constructor
	Blob<string> articles = {"a", "an", "the"}; // three elements

	// instantiates Blob<int> and the initializer_list<int> constructor
	Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};

	// instantiates Blob<int>::size() const
    cout << squares << endl;
	for (size_t i = 0; i != squares.size(); ++i)  
		squares[i] = i*i; // instantiates Blob<int>::operator[](size_t)
    cout << squares << endl;

	// instantiates the Blob<int> constructor that has
	// two vector<long>::iterator parameters
	vector<long> vl = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> a1(vl.begin(), vl.end());   // copy from a vector

	// instantiates the Blob<int> class 
	// and the Blob<int> constructor that has two int* parameters
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> a2(begin(arr), end(arr));   // copy from an array

	list<int> li(10, 0); // 10 elements all zeros
	Blob<int> zeros(li.begin(), li.end());  // copy from a list

    cout << a1 << "\n" << zeros << endl;

	a1.swap(zeros);
    cout << a1 << "\n" << zeros << endl;

	list<const char*> w = {"now", "is", "the", "time"};

	// instantiates the Blob<string> class and the Blob<string> 
	// constructor that has two (list<const char*>::iterator parameters 
	Blob<string> a3(w.begin(), w.end());  // copy from a list

	return 0;
}
