#include <iostream>
using namespace std;

class Animal
{
private:
	string name;

public:
	Animal() {cout << "Animal created" << endl;};
	~Animal() {cout << "Animal destroyed" << endl;};
	void set_name(string name) {this->name=name;};
	void speak() {cout << "My name is " << name << endl;};
};

int main(int argc, char const *argv[])
{
	
	Animal* eagle = new Animal;
	(*eagle).set_name("Bob");
	eagle->speak();

	delete eagle;


	// allocating memory for object, without instantiation
	// allocating memory for array
	Animal* birds = new Animal[10]; // ten Animals created!

	// to access object, have to use array indices
	// does not work with pointer arithmetic !?
	birds[5].set_name("Jules");
	birds[5].speak();

	delete [] birds;

	char* text = new char[1000]; // one char = one byte

	text[1] = 'h';

	delete [] text;

	char a = 'u';
	// char actually just like an integer 
	// (with different interpretation -> ASCII table)
	a++;
	string tztz(10, a);
	a++;	
	cout << tztz << endl; 

	return 0;
}


/*

Exercise

* create class with string (set, get)
* allocate array of length 26
* for each object, set names "A" - "Z"; output name

*/
