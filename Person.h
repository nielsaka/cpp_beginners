#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

// convention (java?): capitalise first letter of class name
// object themselves are lower case
class Person {

private:
	string name;
	int age;

public:

	// constructors = special kind of method

	Person();
	// can add another constructor
	// (here, inline implementation)
	// arguments need to differ from private variables
	Person(string new_name, int new_age) {name = new_name; age = new_age;};
	
	// can have arbitrary number of constructors
	// as long as they differ in their arguments

	// age will not be initialized! random value!
	Person(string new_name) {name = new_name;}; 

	// [better to have implementation in Person.cpp?
	// it gets a bit messy here]
	// could have all the code in header file! 
	// but less clear overview of class


	// same rule applies to other methods
	// there can be several versions under the same name
	// which are differentiated by their parameters

	void introduce();
	string getName();
	void setName(string new_name);
	string toString();
};

#endif // PERSON_H_
