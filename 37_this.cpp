#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Person my_person;
	Person another_person("John", 44);

	cout << my_person.toString() << endl;

	// can also get memory location of my_person;
	// get address via "&"

	cout << "memory location of my_person: " << &my_person << endl;

	cout << another_person.toString() << endl;
	return 0;
}