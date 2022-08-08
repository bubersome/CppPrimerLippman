

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

void printVec(const vector<int> &vi)
{
	// print the vector's elements
	auto iter = vi.begin();
	while (iter != vi.end())
		cout << *iter++ << endl;
}

int main()
{
	// silly loop to remove even-valued elements 
	// and insert a duplicate of odd-valued elements
	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	printVec(vi);

	// we call begin, not cbegin because we're changing vi
	auto iter = vi.begin(); 
	while (iter != vi.end()) {
		if (*iter % 2) {    // if the element is odd
			iter = vi.insert(iter, *iter);  // duplicate  it
			iter += 2; // advance past this element and the new one 
		} else 
			iter = vi.erase(iter);          // remove even elements
			// don't advance the iterator; 
			// iter denotes the element after the one we erased
	}
	printVec(vi);

	return 0;
}
	
