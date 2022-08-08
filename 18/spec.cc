

#include <iostream>
using std::cout; using std::endl;

#include <exception>
using std::exception;

// this function will compile, even though it clearly violates its exception specification
void f() noexcept       // promises not to throw any exception
{
    throw exception();  // violates the exception specification
}

void g() { }
void h() noexcept(noexcept(f())) { f(); }
void i() noexcept(noexcept(g())) { g(); }
int main()
{
    try {
		cout << "f: " << std::boolalpha << noexcept(f()) << endl;
		cout << "g: " << std::boolalpha << noexcept(g()) << endl;
		cout << "h: " << std::boolalpha << noexcept(h()) << endl;
		cout << "i: " << std::boolalpha << noexcept(i()) << endl;
        f();
    } catch (exception &e) {
        cout << "caught " << e.what() << endl;
    }
	
	return 0;
}
