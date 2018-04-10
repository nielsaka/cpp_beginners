#include "iostream"
#include "Cat.h"
using namespace std;

// How to "build project" ? What does Eclipse do exactly?

// What's the point of header files? Why not the source directly? abstraction?
// -> easy transition to declaring class (with specifics of implementation elsewhere?)


// http://www.cplusplus.com/forum/articles/10627/ lists the following

// speed (no need to recompile huge file)
// organisation: separation of concepts; 
// abstraction: separation of interface and implementation

// "Header files allow you to make the interface [...] visible to other .cpp files, while keeping the implementation [...] in its own .cpp file"
// "The #include statement is basically like a copy/paste operation."

// building binary programmes: compiler does it in two steps
// 		1) compile individual files
// 		2) link output
// need to tell compiler all source files! and location of header files via -I if necessary

// e.g.
// g++ -o Cat.out 31_classes.cpp Cat.cpp
// ./Cat.out 
//> meeouaw


// Watch out: do not #include same header several times (unless using trick with #ifndef ?!) - that trick is called "Include Guard". good practice to #include where needed (even in header file). --> "Always guard your headers. Always always always."

// 

int main(int argc, char const *argv[])
{
	// declare instance of class "Cat" (§)
	// object of type "Cat"
	// object instantiated from the class
	Cat my_cat;

	my_cat.speak();
	my_cat.jump();


	return 0;
}

/* (§) sidenote
declaration : "Declaration means creating a variable"
		int a;
assignment : assign value to variable
		a = 10;
Initialization = Declaration + Assignment in a single step
		int a = 10;

Source: https://www.quora.com/What-is-the-difference-between-variable-declaration-vs-initialization
