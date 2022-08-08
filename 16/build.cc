

#include "Blob.h"
#include "compare.h"

#include <string>
using std::string;

// templateBuild.cc
// instantiation file must provide a (nonextern) definition for every
// type and function that other files declare as extern
template int compare(const int&, const int&);
template class Blob<string>; // instantiates all members of the class template 
template class Blob<int>;    // instantiates Blob<int>
