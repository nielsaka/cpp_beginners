#include <iostream>
using namespace std;

class Animal
{
private:
	string name;
public:
	void set_name(string name) {this->name=name;};
	void speak() const {cout << "My name is " << name << endl;};
	Animal() {cout << "Animal created" << endl;};

	// copy constructor explicitly defined
	// will it copy + initialise any fields? 
	// 'other' animal object passed on to this constructor
	// can access private fields of other

	// Animal(const Animal& other) {name = other.name; cout << "Animal created by copying" << endl;};

	// alternatively, constructor initialisation list (more efficient?)
	// if using explicit copy constructor, need to copy values of all variables
	Animal(const Animal& other): name(other.name) {other.speak();  cout << "Animal created by copying" << endl;};
	// const - do not change original object! will disallow non-const methods.
	// e.g. if speak() weren't const, would not be able to call it
	
	// Animal& - a reference to the original object


	//~Animal(); // WHAT IS THIS AGAIN? it is the destructor
	
};


int main(int argc, char const *argv[])
{
	Animal tiger;
	tiger.set_name("Blueberry");

	Animal lion = tiger; // will not call constructor
	tiger.speak();
	lion.speak();

	lion.set_name("Raspberry");
	lion.speak();

	// why no second call to Animal() ? 
	// line 22 uses the copy constructor which was implicitly created
	// can also be explicitly defined

	// alternative syntax using copy constructor
	Animal lioness(lion);
	lioness.set_name("Brigitte");
	lioness.speak();

	// = operator: implicitly defined for objects depending on type (?) 
	// default implementation
	return 0;
}