

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

string st1;       // empty string
string st2(st1);  // st2 is a copy of st1

int main()
{
    string st("1234567\n");
    cout << "The size of " << st << "is " << st.size()
         << " characters, including the newline" << endl;
    return 0;
}
