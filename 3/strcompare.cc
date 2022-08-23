//3.2.2 Comparing string s

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang  = "Hiya";
    string A = "A";
    string X = "X";


    if (str < phrase) cout << "str is smaller" << endl;
    if (slang > str) cout << "slang is greater" << endl;
    if (slang > phrase) cout << "slang is greater" << endl;
    cout << (A < slang)<< endl;
    cout << (X < slang)<< endl;
    return 0;
}
