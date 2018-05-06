#include <iostream>
#include "Cat.h"
#include "Animals.h"
using namespace cat; // make all classes/structures(?) available in namespace

/*

avoid conflicts between classes or variables that have same name

*/

int main(int argc, char const *argv[])
{
	Cat lucy;
	lucy.speak();

	animals::Cat theodor; // access specific class in specific namespace
	theodor.speak();

	cout << "animals live on " << animals::WORLD << endl;
	cout << "but cats live on " << cat::WORLD << endl;

	return 0;
}