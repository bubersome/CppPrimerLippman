//6.1.1

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

size_t count_calls()
{
//	static size_t ctr = 0;  // value will persist across calls
	int ctr = 0;  // print 1s
	return ++ctr;
}

int main() 
{
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << endl;
	return 0;
}
