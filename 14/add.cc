

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "Sales_data.h"
#include "Sales_item.h"

int main() 
{
    Sales_item item1, item2;
    cin >> item1 >> item2;   //read a pair of transactions
    // print the sum of two Sales_items
    cout << item1 + item2 << endl; 

	Sales_data data1, data2;
    read(read(cin, data1), data2);   //read a pair of transactions
    print(cout, add(data1, data2));  // print the sum of two Sales_datas
 	cout << std::endl; 

	cin >> data1 >> data2; // use input operator to read Sales_datas
    // use operators to print the sum of two Sales_datas
    cout << data1 + data2 << endl;

    return 0;
}
