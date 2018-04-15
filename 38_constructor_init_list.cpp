#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Person person1("John", 71);
	Person person2("Lilly", 28);
	Person person3;

	cout << person1.toString() << endl;
	cout << person3.toString() << endl;

	return 0;
}