#ifndef CAT_H_
#define CAT_H_

/*
// if not listed here, comiler complains
//  "error: ‘jump’ was not declared in this scope"

void speak();
void jump();

*/

// classes: bundle data (=state) and methods together
// here, just blueprint (=class)

class Cat {
public: 
	// these methods are accessible from outside of object/class (scope?)
	// exported? only accessible via an object of type "Cat"
	void speak();
	void jump();
};

#endif