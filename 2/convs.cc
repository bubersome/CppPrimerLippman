//2.3.2

#include <iostream>
int main()
{
	int i = 42;
	std::cout << i << std::endl; // prints 42
	if (i) // condition will evaluate as true
		i = 0;
	std::cout << i << std::endl; // prints 0

	bool b = 42;            // b is true
	std::cout << b << std::endl; // prints 1

	int j = b;              // j has value 1
	std::cout << j << std::endl; // prints 1

	double pi = 3.14;       // pi has value 3.14
	std::cout << pi << std::endl; // prints 3.14

	j = pi;                 // j has value 3
	std::cout << j << std::endl; // prints 3

	unsigned char c = -1;   // assuming 8-bit chars, c has value 255
	i = c;  // the character with value 255 is an unprintable character
	        // assigns value of c (i.e., 255) to an int
	std::cout << i << std::endl; // prints 255

    double obj = 3.14, *pd = &obj;// ok: void* can hold the address value of any data pointer type
    void *pv = &obj; // obj can be an object of any type
    pv = pd;     // pv can hold a pointer to any type
    std::cout << pv << std::endl; // prints 255
    std::cout << pd << std::endl; // prints 255
    pd+= 2*2*2*2*2*2*2*2 ;
    std::cout << *pd << std::endl; // prints 255
//Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
//    int i = 42;
    int &r = i;  // & follows a type and is part of a declaration; r is a reference
    int *p;    // * follows a type and is part of a declaration; p is a pointer
    p = &i;    // & is used in an expression as the address-of operator
    *p = i;    // * is used in an expression as the dereference operator
    int &r2 = *p; // & is part of the declaration; * is the dereference operator
    std::cout << r2 << std::endl; // prints 255
    std::cout << &r2 << std::endl; // prints 0x16d9ff588

    return 0;
}
