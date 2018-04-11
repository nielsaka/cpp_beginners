#ifndef CAT_H_
#define CAT_H_

/*
// if not listed here, comiler complains
//  "error: ‘jump’ was not declared in this scope"

void speak();
void jump();

*/

// classes: bundle data (=state) and methods together
// here, just blueprint (=class)

class Cat {
private:
	// will not be initialized! use constructor (in c++98)
	// value will be garbage; any random value.
	bool happy; 

public: 
	// these methods are accessible from outside of object/class (scope?)
	// exported? only accessible via an object of type "Cat"
	void speak();
	void jump();
	void pet();
	void shower();

	// in C++98, use constructor
	Cat(); // no return type

	// use destructor
	~Cat();

	// avoid manipulation of data from outside! do not want to make variables public
	// instead, encapsulate in class and surface via get/set method (?)
	// better for keeping interface and implementation separate and to reason about code
	
	// bool happy;
};

#endif


/*

in c++11, can set default values for variables -> compile "g++ -std=c++11 ..."
	e.g bool happy = true;

otherwise, use constructor.

*/