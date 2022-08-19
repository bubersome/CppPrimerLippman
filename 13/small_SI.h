
#ifndef SMALL_SI_H
#define SMALL_SI_H

// This file isn't used in our code, but illustrates the
// definitions that are equivalent to Sales_data's 
// synthesized copy control members 

#include <string>

class Sales_data {
public:
    Sales_data(const std::string & s = ""): bookNo(s),
                                          units_sold(0), revenue(0.0) { }

	Sales_data(const std::string &book, unsigned cnt, double price):
	        bookNo(book), units_sold(cnt), revenue(cnt * price) { }

	// equivalent to the synthesized copy constructor
	Sales_data(const Sales_data &rhs): bookNo(rhs.bookNo),
                    units_sold(rhs.units_sold), revenue(rhs.revenue) { }

	// equivalent to the synthesized destructor
	// no work to do other than destroying the members, 
	// which happens automatically
    ~Sales_data() { } 
   
    Sales_data& operator=(const Sales_data &); // assignment operator
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// equivalent to the synthesized copy-assignment operator
Sales_data& 
Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;          // calls the string::operator=
	units_sold = rhs.units_sold;  // uses the built-in int assignment
	revenue = rhs.revenue;        // uses the built-in double assignment
	return *this;                 // return a reference to this object
}

#endif
