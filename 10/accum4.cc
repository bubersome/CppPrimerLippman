

#include <numeric>
using std::accumulate;

#include <iterator>
using std::istream_iterator;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	istream_iterator<int> in(cin), eof;
	cout << accumulate(in, eof, 0) << endl;
	return 0;
}
