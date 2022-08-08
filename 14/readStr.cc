

#include <algorithm>
using std::for_each;

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::istream; using std::ostream;

#include <string>
using std::string; 

#include <vector>
using std::vector;

class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '): 
		os(o), sep(c) { }
    void operator()(const string &s) const { os << s << sep; }
private:
    ostream &os;   // stream on which to write
	char sep;      // character to print after each output
};

class ReadLine {
public:
	ReadLine() = delete;
	ReadLine(istream &i) : is(i) { }
	bool operator()(string &s) const { return getline(is, s); }
private:
	istream &is;
};

int main()
{
	vector<string> vs;
	ReadLine rl(cin);    // object that read lines from cin
	string s;
	while (rl(s))        // store what rl reads into s
		vs.push_back(s);

	cout << "read : " << vs.size() << " elements" << endl;
	PrintString printer;   // uses the defaults; prints to cout 
	printer(s);            // prints s followed by a space on cout

	PrintString errors(cerr, '\n');
	errors(s);             // prints s followed by a newline on cerr

	cerr << "for_each printing to cerr" << endl;
	for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
}

