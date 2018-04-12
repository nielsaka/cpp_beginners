#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Person my_person;

	my_person.introduce(); // this is not a getter in the traditional sense!


	// get / set : "almost as bad as exposing variable directly"
	// "but not quite as bad": have documented standard access; implementation can
	// change, interface stays constant
	cout << "Hi again, my name is still " << my_person.getName() << endl;

	my_person.setName("Johnny");
	cout << "Hi again, now my name is " << my_person.getName() << endl;



	return 0;
}