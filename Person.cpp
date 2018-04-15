#include "Person.h"
#include <sstream>

// onyl for constructors: constructor initialisation list
Person::Person(): name("Geoffrey") { //, age(0) {
	// can also mix initialisation via list above
	// or details down here in function body
	age = 99;
}

void Person::introduce() {
	cout << "Hello, my name is " << name << endl;
}

string Person::getName() {
	return name;
}

void Person::setName(string new_name) {
	name = new_name;
}

string Person::toString() {
	stringstream ss;

	ss << "Name: " << name << "; age: " << age;

	return ss.str();
}