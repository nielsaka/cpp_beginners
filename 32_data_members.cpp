#include <iostream>
#include "Cat.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Cat jim_the_cat;

	cout << "stroking jim-the-cat ..." << endl;
	jim_the_cat.pet();
	cout << "jim says " << flush;
	jim_the_cat.speak();

	cout << "showering jim-the-cat ..." << endl;
	jim_the_cat.shower();
	cout << "jim says " << flush; 
	jim_the_cat.speak();

	return 0;
}