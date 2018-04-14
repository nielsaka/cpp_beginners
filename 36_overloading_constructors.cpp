#include <iostream>
#include "Person.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Person my_person;

	cout << my_person.toString() << endl;

	// C++ compiler will figure out which constructor is needed
	Person another_person("Bob", 22);

	cout << another_person.toString() << endl;
	
	Person yet_another_person("Bob"); // age is unitialized

	cout << yet_another_person.toString() << endl;
	return 0;
}


/*

here, have instantiated class three times
have three instances of class
three objects

*/