//6.2.2

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c, 
                           string::size_type &occurs)
{
    auto ret = s.size();   // position of the first occurrence, if any
    occurs = 0;            // set the occurrence count parameter 

    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) 
                ret = i;   // remember the first occurrence of c
            ++occurs;      // increment the occurrence count
         }
	}
    return ret;            // count is returned implicitly in occurs
}

// returns an iterator that refers to the first occurrence of value
// the reference parameter occurs contains a second return value
vector<int>::const_iterator find_val(
    vector<int>::const_iterator beg,  // first element
    vector<int>::const_iterator end,  // one past last element
    int value,                        // the value we want
    vector<int>::size_type &occurs)   // number of times it occurs
{
    auto res_iter = end; // res_iter will hold first occurrence, if any
    occurs = 0;          // set occurrence count parameter 

    for ( ; beg != end; ++beg)
        if (*beg == value) {
            // remember first occurrence of value
            if (res_iter == end) 
                res_iter = beg;
            ++occurs;    // increment occurrence count
         }

    return res_iter;     // count returned implicitly in occurs
}

int main() 
{
	
	string s;
    s = {"dsfsdfo"};
	getline(cin, s); 
	size_t ctr = 0;
	auto index = find_char(s, 'o', ctr);
	cout << index << " " << ctr << endl;
	
	vector<int> ivec;
	int i;
	// read values into ivec
	while (cin >> i)
		ivec.push_back(i);
    cout<< ivec.size() <<endl;
	// for each value in the list of ints
	for (auto iTargetList : {42, 33, 92}) {
		auto it = find_val(ivec.begin(), ivec.end(), iTargetList, ctr);
		if (it == ivec.end())
			cout << iTargetList << " is not in the input data" << endl;
		else
			cout << iTargetList << " was at position "
                 << it - ivec.begin() << endl;
	}

	return 0;
}
