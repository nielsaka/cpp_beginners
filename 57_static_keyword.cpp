#include <iostream>
using namespace std;

// normally in header file
class test
{
public:
	static int count; // shared among all objects
};
// normally in .cpp file
int test::count = 8;

class test2
{
private:
	static int count; // declare
public:
	// static methods can only access static variables
	// otherwise dependent on instantiation!
	static void info() {cout << count << endl;};
};

int test2::count = 10; // initialise

// static useful for constants
class blume
{
public:
	// const must be initialised when declared
	// static const cannot be changed -> can make public
	static int const MAX_BLAETTER = 12;
};

// static useful for keeping count on number of objects
class ente
{
private:
	int id;
public:
	static int count; // cannot init here
	int get_id() {return(id);};
	ente() {id = ++count;};

	// sidenote: prefix vs. postfix increment operator
	// prefix: 	increment prior assignment
	// postfix: increment post assignment

	// ente() {id = ++count;}; 

	// ente() {id = count++;}; 
};
// init static
int ente::count = 0;

int main(int argc, char const *argv[])
{
	cout << test::count << endl;
	// have not instantiated class yet !!

	// 1. static methods
	test2::info();

	// 2. public constants
	cout << blume::MAX_BLAETTER << endl;

	// 3. counting objects
	cout << "Number of ducks: " << ente::count << endl;

	ente maya;
	ente hilda;
	cout << "Number of ducks: " << ente::count << endl;

	cout << "ID: " << hilda.get_id() << endl;
	return 0;
}


// Exercise

// define and output a public static constant
// define and output a non-static field
// output a static field with static method
// increment static int with postfix and prefix increment operators
// assign object ID based on static count (init in constructor)
// but class def in .h and implementation in .cpp !!
// init static fields in class.cpp