

#include <functional>
using std::plus; using std::negate;
using std::function; using std::placeholders::_1;
using std::bind; using std::less_equal; 

#include <iostream>
using std::cout; using std::endl;

#include <algorithm>
using std::count_if; 

#include <vector>
using std::vector;

#include <iostream>
using std::cin;

#include <string>
using std::string; 

bool size_compare(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int main() {

	cout << plus<int>()(3,4) << endl; // prints 7
	
	plus<int> intAdd;      // object that can add two int values
	negate<int> intNegate; // object that can negate an int value
	
	// uses intAdd::operator(int, int) to add 10 and 20
	int sum = intAdd(10, 20);         // equivalent to sum = 30
	cout << sum << endl;
	
	sum = intNegate(intAdd(10, 20));  // equivalent to sum = -30
	cout << sum << endl;
	
	// uses intNegate::operator(int) to generate -10 
	// as the second argument to intAdd::operator(int, int)
	sum = intAdd(10, intNegate(10));  // sum = 0
	
	cout << sum << endl;
	
	vector<int> vec = {0,1,2,3,4,5,16,17,18,19};
	
	// bind second argument to less_equal
	cout << count_if(vec.begin(), vec.end(),
		             bind(less_equal<int>(), _1, 10));  
	cout << endl;
	
	vector<string> svec;
	string in;
	while (cin >> in) 
		svec.push_back(in);

	function<decltype(size_compare)> fp1 = size_compare;

	//decltype(fp1)::result_type ret;
	function<bool(const string&)> fp2 = bind(size_compare, _1, 6);
	cout << count_if(svec.begin(), svec.end(), fp2)
	     << endl;
	cout << count_if(svec.begin(), svec.end(), 
	                 bind(size_compare, _1, 6))
	     << endl;


	return 0;
}
