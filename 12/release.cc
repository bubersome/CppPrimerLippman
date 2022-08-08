

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	unique_ptr<string> p1(new string("Stegosaurus"));
	
	// transfers ownership from p1 
	// (which points to the string Stegosaurus) to p2
	unique_ptr<string> p2(p1.release()); // release makes p1 null
	cout << *p2 << endl; // prints Stegosaurus
	
	unique_ptr<string> p3(new string("Trex"));

	// reset deletes the memory to which p2 had pointed
	// and transfers ownership from p3 to p2 
	p2.reset(p3.release()); 
	cout << *p2 << endl; // prints Trex
	
	// p1 is null, p2 is steg, and p3 is trex
	if (p1)
		cout << "p1 not null?" << endl;
	if (p3)
		cout << "p2 not null?" << endl;
	cout << *p2 << endl;
}
