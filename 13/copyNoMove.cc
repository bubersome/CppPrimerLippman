

#include <utility>
#include <iostream>

class Foo {
public:
	Foo() = default;  // default constructor needed because Foo has a copy constructor
	Foo(const Foo&);  // copy constructor
	// other members, but Foo does not define a move constructor
};

Foo::Foo(const Foo&) { std::cout << "Foo copy ctor" << std::endl; }

int main()
{
	Foo x;
	Foo y(x);            // copy constructor; x is an lvalue
	Foo z(std::move(x)); // copy constructor, because there is no move constructor
}
