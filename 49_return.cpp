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
Animal create_animal(string name) {
	Animal a_l;
	a_l.set_name(name);
	return a_l;
}

Animal& create_animal_BAD(string name) {
	Animal a_l;
	a_l.set_name(name);
	return a_l;
}

Animal* create_animal_BETTER(string name) {
	Animal* p_a_l = new Animal();
	p_a_l->set_name(name);
	return p_a_l;
}

int main(int argc, char const *argv[])
{
	Animal* p_lion = new Animal();
	p_lion->set_name("Blueberry");
	p_lion->speak();

	delete p_lion;
	
	Animal eagle = create_animal("Faith");
	eagle.speak();
	
	// would expect this approach to be inefficient

	// when returning an object from function, c++ would copy
	// object to temporary object and then copy again during 
	// assignment in main()

	// would expect two calls to copy constructor

	// BUT, compiler optimises away extra copys
	// could potentially be inefficient if compiler does not optimise

	// Naive solution: pass on reference
	if (false) {
		Animal& dove = create_animal_BAD("Judy"); // warning: "reference to local variable ‘a_l’ returned "
		dove.speak();
	}

	// scope of a_l ends at last curly bracket of function create_animal()
	// usually, object will be destroyed. If it works, it is only by chance.
	// BAD IDEA: returning reference to local variable

	// BETTER: return pointer and use "new"
	// 1) no calls to copy constructor
	// 2) if object huge, will only pass on pointer (8 bytes!); not huge object
	// 3) no out-of-scope problem: object will exist after function scope has ended

	// downside: need to call delete manually...

	Animal* p_snake = create_animal_BETTER("Peter");
	p_snake->speak();
	delete p_snake;

	// sidenote: two areas of memory

	// 1) stack

	// "stack of plates"
	// plates = memory addresses of local variables
	// what is a local variable? objects, functions; or calls to functions?
	// stackoverflow: running out of memory in stack (e.g. recursive fn calling itself?)

	// 2) heap

	// "new" : allocating memory on the heap

	return 0;
} 

/*
PRACTICE
---------

* 

*/