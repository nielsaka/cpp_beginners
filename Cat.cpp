#include <iostream>
#include "Cat.h"

using namespace std;

void Cat::speak(){

	if (happy) {
		cout << "meeouaw" << endl;
	} else {
		cout << "sssss" << endl;
	}
}

void Cat::jump() {

	cout << "jumping to top of bookcase" << endl;
}

void Cat::pet() {
	happy = true;
}

void Cat::shower() {
	happy = false;
}