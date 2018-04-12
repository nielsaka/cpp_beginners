#include "Person.h"

Person::Person() {
	name = "Geoffrey";
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