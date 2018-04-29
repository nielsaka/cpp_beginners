#include <iostream>
using namespace std;

class Animal
{
private:
	string name;
public:
	// constructor (called whenenver no argument passed on)
	Animal() {
		cout << "Animal created" << endl;
	};
	// copy constructor (called when object of type Animal passed on)
	Animal(const Animal& other) :
		name(other.name) {
		cout << "Animal created by copying" << endl;
	};
	// destructor
	~Animal() {
		cout << "Animal destroyed" << endl;
	};
	void set_name(string name){
		this->name = name;
	};
	void speak() {
		cout << "my name is " << name << endl;
	};	
};

int main(int argc, char const *argv[])
{
	// Animal tiger;
	// instead of handling object directly, can use pointer
	// new: allocate memory yourself!
	Animal* p_lion = new Animal();

	// Won't work
	// p_lion.set_name("Detlef");
	// . has higher precedence than *
	// first call to method, then de-reference
	//*p_lion.set_name("Dieter");
	
	// Works
	(*p_lion).set_name("Dudley");
	(*p_lion).speak();

	// shortcut notation
	p_lion->speak();

	// source of bugs or memory leakage: not calling delete
	delete p_lion;

	// another source of bugs
	// practice of setting pointer to null to note that it is not pointing anywhere
	// MISTAKE: calling delete on a null pointer (here, it runs smoothly?)
	Animal* p_cat = new Animal;
	p_cat = NULL;
	delete p_cat; // is there still a cat floating around?

	// sidenote: subtracting pointers

	Animal* p_mouse = new Animal;
	Animal* p_rat = new Animal;

	// store difference in long
	long diff = p_mouse - p_rat;

	// because size of pointer is (usually!) equal to long;
	cout << "Size of pointer: " << sizeof(p_mouse) << endl;

	delete p_mouse;
	delete p_rat;

	return 0;
} 
// scope of tiger ends -> object destroyed, memory de-allocated
// Dudely is not destroyed! when using "new", have to do it yourself
// ---> call "delete" whenever using "new" !

/*
PRACTICE
---------

* extract class into header and separate cpp file
* create class, constructor, destructor, call new, delete, -> syntax

*/