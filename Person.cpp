#include "Person.h"
#include <sstream>

Person::Person() {
	name = "Geoffrey";
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