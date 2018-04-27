#include <iostream>

using namespace std;

class Animal
{
private:
	string name;
public:
	void set_name(string name) {this->name=name;};
	
	// WILL NOT WORK:
	/*
	void speak() const {cout << "My name is " << name << endl; name = "bla"};
	*/
	// would have to remove "const" keyword
	// but "const" is useful for avoiding bugs, making sure state is not changed
	void speak() const {cout << "My name is " << name << endl;};
};


int main(int argc, char const *argv[])
{
	// const is an important tool

	const int value = 7; 
	cout << "value is " << value << endl;
	// variable can vary of course; but now it's const
	// can't change
	/*
	value = 10;
	cout << "value is " << value << endl;
	*/

	// convention: use upper case for constants
	// const int PI = 3.141592;

	// -----> So easy to fall into trap
	// it has to be double, of course!
	const double PI = 3.141592;

	// not just unique to variables, but also methods
	// example using class Animal
	Animal animal;
	animal.set_name("Fred");
	animal.speak();

	// those methods that do not / should not change any data
	// can be declared const (see above)
	// these methods will not be able to change an object's / instance' data

	//===============
	// Another topic
	// const can get tricky

	int my_val = 8;
	int* my_pointer = &my_val;

	cout << "The target of pointer is: " << *my_pointer << endl;

	int number = 11;

	my_pointer = &number;
	cout << "The target of pointer is: " << *my_pointer << endl;
	
	cout << "The contents of number is " << number << endl;
	*my_pointer = 12;
	cout << "... changing contents of memory location ..." << endl;
	cout << "The target of pointer is: " << *my_pointer << endl;
	cout << "Now, the contents of number is: " << number << endl;

	// 1. can change where the pointer points
	// 		--> change address
	// 2. can change the contents of where the pointer points 
	// 		--> by dereferencing the pointer and new assignment

	cout << "======================" << endl;
	// turn off second channel
	cout << "Using a pointer of type 'const int*' " << endl << endl;

	// pointer to an int that is constant (even though number wasn't const int)
	const int* ppp = &number;
	cout << "The number is " << number << endl;
	cout << "trying to change the value of pointer's target via pointer ..." << endl;
	/*
	*ppp = 15;
	*/
	cout << "error: assignment of read-only location ‘* ppp’" << endl;

	number = 15;
	cout << "trying to change the value of pointer's target directly ..." << endl;
	cout << "The number is " << number << endl; // works 

	cout << "======================" << endl;
	// turn off first channel
	cout << "Using a pointer of type 'int* const' " << endl << endl;

	int* const qqq = &number;

	cout << "1. Number: " << number << endl;
	cout << "trying to change value stored at address of where pointer points to..." << endl;
	*qqq = 20;
	cout << "2. Number: " << number << endl;
	/*
	qqq = &value;
	*/
	cout << "trying to change address of where pointer points to ..." << endl;
	cout << "error: assignment of read-only variable ‘qqq’" << endl;

	cout << "================" << endl;
	// combine both
	// won't be able to either change address or value stored at address
	const int* const rrr = &value;

	// ========================================

	// how to read types:

	// backwards

	// ========================================
	// How about referencing a const?

	const string blumenstrauss = "schoen";

	const string* vase = &blumenstrauss; 
	// has to be const string*
	// string* will not work

	cout << "Der Inhalt der Vase ist " << *vase << endl;
	// can change? no, of course not this way.
	/*
	*vase = "verwelkt";
	*/
	cout << "Der Inhalt der Vase ist " << *vase << endl;


	// but, pointer itself is not const
	string rose = "duftet!";
	vase = &rose; // works, even though pointer type is const string*
	cout << "Die Vase " << *vase << endl;
	rose = "stiiinks"; 
	cout << "Die Vase " << *vase << endl;

	// still can't change the value of 'rose' via the pointer
	/*
	*vase = "braucht Wasser"; 
	*/
	// So, const string* can point to a string, but const string cannot be
	// pointed at by a string*. Makes sense, as otherwise would be able to
	// change value of const string via the pointer.

	return 0;
}