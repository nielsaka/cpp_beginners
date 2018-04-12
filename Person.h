#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

// convention (java?): capitalise first letter of class name
// object themselves are lower case
class Person {

private:
	string name;

public:
	Person();
	void introduce();
	string getName();
	void setName(string new_name);
};



#endif // PERSON_H_
