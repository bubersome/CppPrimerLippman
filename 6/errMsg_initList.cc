

#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

#include <initializer_list>
using std::initializer_list;

#include <sstream>
using std::ostringstream;

// chapter 7 will explain the code used in defining ErrCode
struct ErrCode { 
	ErrCode(int i) : num(i) { }  // initializes objects of type ErrCode
	string msg()                 // member function of ErrCode
	{ ostringstream s; s << "ErrCode " << num; return s.str(); }
	int num;  // data member, note uninitialized
};

// version that takes an ErrCode and a list of strings
void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";
	for (const auto &elem : il)
		cout << elem << " " ;
	cout << endl;
}

// overloaded version takes only a list of strings
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " " ;
	cout << endl;
}

// function to illustrate list initializing return value
vector<string> functionX()
{
	string expected = "description", actual = "some other case";
	// . . .
	if (expected.empty())
		return {};  // return an empty vector
	else if (expected == actual)
		return {"functionX", "okay"}; // return list-initialized vector
	else 
		return {"functionX", expected, actual}; 
}
	
int main()
{
	string expected = "description", actual = "some other case";
	initializer_list<int> li = {0,1,2,3};

	// expected, actual are strings 
	if (expected != actual)
		error_msg({"functionX", expected, actual});
	else
		error_msg({"functionX", "okay"});

	// expected, actual are strings 
	if (expected != actual)
		error_msg(ErrCode(42), {"functionX", expected, actual});
	else
		error_msg(ErrCode(0), {"functionX", "okay"});
	
	// can pass an empty list, calls second version of error_msg
	error_msg({}); // prints blank line

	// call function that list initializes its return value
	// results is a vector<string>
	auto results = functionX();
	for (auto i : results) 
		cout << i << " ";
	cout << endl;
}

