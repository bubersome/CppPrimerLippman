

#include "Sales_data.h"
#include "bookexcept.h"

#include <iostream>
using std::cin; using std::cerr; using std::endl;

int main()
{
    // use the hypothetical bookstore exceptions 
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2) {  // read two transactions
        try {
            sum = item1 + item2;     // calculate their sum
            // use sum
        } catch (const isbn_mismatch &e) {
          cerr << e.what() << ": left isbn(" << e.left
               << ") right isbn(" << e.right << ")" << endl;
        }
    }
     return 0;
}
