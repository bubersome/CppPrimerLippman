//3.2.3

#include <string>
using std::string;

#include <cctype>
using std::isupper; using std::toupper;
using std::islower; using std::tolower;
using std::isalpha; using std::isspace;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string s("Hello World!!!1");
	// punct_cnt has the same type that s.size returns
	decltype(s.size()) punct_cnt = 0;
//	unsigned punct_cnt = 0;

	// count the number of punctuation characters in s
//	for (char c : s)         // for every char in s
	for (char &c : s)         // for every char in s
//		if (ispunct(c))      // if the character is punctuation
		if (ispunct(*&c))      // if the character is punctuation
			++punct_cnt;     // increment the punctuation counter
	
	cout << punct_cnt 
	     << " punctuation characters in " << s << endl;
	
	// convert s to uppercase
	string orig = s;
	for (char &c : s)   // for every char in s (note: c is a reference)
		// c is a reference, so this assignment changes the char in s
		c = toupper(c);
	cout << s << endl;
	
	// convert first word in s to uppercase
	s = orig;  // restore s to original case
	auto index = 0;

	// process characters in s until we run out of characters 
	// or we hit a whitespace
	while (index != s.size() && !isspace(s[index])) {

	    // s[index] returns a reference so we can change 
		// the underlying character
		s[index] = toupper(s[index]);

		// increment the index to look at the next character 
		// on the next iteration
		++index; 
	}
	cout << s << endl;
	
	return 0;
}
