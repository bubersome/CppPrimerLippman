

#ifndef VERSION_TEST_H
#define VERSION_TEST_H


/* As of the first printing of C++ Primer, 5th Edition (July 2012), 
 * the gcc Version 4.7.0 did not yet support some C++ 11 features.  
 *
 * The code we distribute contains both normal C++ code and 
 * workarounds for missing features.  We use preprocessor variables to
 * determine whether a given features is implemented in a given release
 * of the compiler.  
 * The base version we used to test the code in the book
 * is gcc version 4.7.0 (GCC) 
 *
 * When new releases are available we will update this file which will
 * #define the features implmented in that release.
*/

#if __cplusplus == 201103L 
// base version, future releases of this file will 
// #define these variables as features as they are implemented 

/* Code in this delivery use the following variables to control compilation

   Variable tests           C++ 11 Feature 
HEX_MANIPS               hexfloat and defaultfloat manipulators
REFMEMS                  reference qualified member functions
REGEX                    regular expressions library
STRING_NUMERIC_CONVS     conversions to and from string to numeric
*/
#endif  // ends compiler version check

#ifndef STRING_NUMERIC_CONVS
// if the library doesn't define to_string 
// or the numeric conversion functions
// as a workaround we define to_string and stod in this file

// Readers can ignore the implemnetations of to_string and stod 
// but can use these functions in their code.

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
// we use sprintf from stdio to implement to_string
#include <cstdio>

inline
std::string to_string(int i)
{
	char buf[100];
	std::sprintf(buf, "%d", i);
	return buf;
}

inline
double stod(const std::string &s, std::size_t * = 0)
{
	char **buf = 0;
	return std::strtod(s.c_str(), buf);
}
#endif   // STRING_NUMERIC_CONVS

#include <iostream>

#ifndef HEX_MANIPS
inline
std::ostream &defaultfloat(std::ostream &os) 
{
	os.unsetf(std::ios_base::floatfield);
	return os;
}
#endif   // HEX_MANIPS

#endif  // ends header guard

