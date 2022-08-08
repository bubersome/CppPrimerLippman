

#include <cstdio> // for EOF
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	char ch;    // using a char here invites disaster!

	// the return from cin.get is converted to char 
	// and then compared to an int
	while ((ch = cin.get()) != EOF)
         	cout.put(ch);
	cout << endl;

	return 0;
}
