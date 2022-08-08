

#include "Sales_data.h"

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
	Sales_data data1, data2;
	std::cin >> data1 >> data2;    // read Sales_data transactions
	cout << data1 + data2 << endl; // write sum of Sales_data objects
	cout << 42 + 5 << endl;        // write sum of ints
	
	// equivalent calls to a nonmember operator function
	data1 + data2;            // normal expression
	operator+(data1, data2);  // equivalent function call
	cout << operator+(data1, data2) << endl;
	
	data1 += data2;           // expression-based ``call''
	data1.operator+=(data2);  // equivalent call to a member operator function
	cout << data1 << endl;
	
	return 0;
}
