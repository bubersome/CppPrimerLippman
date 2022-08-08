

#include <iostream>
using std::cout; using std::endl; using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind; using std::function;
using namespace std::placeholders;

// ordinary function
int add(int i, int j) { return i + j; }

// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j) { return i % j; };

// function-object class
// In the first printing we named this struct div, but that name conflicts with
// the name of a C library function.  Compilers are permitted to put
// C library names in the global namespace.  Future printings will
// change the name of this calss to divide.
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
	function<int(int, int)> f1 = add;      // function pointer
	function<int(int, int)> f2 = divide(); // callable class type
	function<int(int, int)> f3 = [](int i, int j) // lambda
	                             { return i * j; };
	cout << f1(4,2) << endl; // prints 6
	cout << f2(4,2) << endl; // prints 2
	cout << f3(4,2) << endl; // prints 8

	// table of callable objects corresponding to each binary operator
	// all the callables must take two ints and return an int
	// an element can be a function pointer, function object, or lambda
	map<string, function<int(int, int)>> binops = {
		{"+", add},                  // function pointer
		{"-", std::minus<int>()},    // library function object
		{"/",  divide()},            // user-defined function object
		{"*", [](int i, int j) { return i * j; }}, // unnamed lambda
		{"%", mod} };                // named lambda object

	cout << binops["+"](10, 5) << endl; // calls add(10, 5)
	cout << binops["-"](10, 5) << endl; // uses the call operator of the minus<int> object
	cout << binops["/"](10, 5) << endl; // uses the call operator of the divide object
	cout << binops["*"](10, 5) << endl; // calls the lambda function object
	cout << binops["%"](10, 5) << endl; // calls the lambda function object

	return 0;
}
