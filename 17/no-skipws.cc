

#include <iostream>
using std::cin; using std::cout;
using std::noskipws; using std::skipws;

int main()
{
	char ch;
	cin >> noskipws;  // set cin so that it reads whitespace
	while (cin >> ch)
		cout << ch;
	cin >> skipws;    // reset cin to the default state 
	                  // so that it ignores whitespace

	return 0;
}
