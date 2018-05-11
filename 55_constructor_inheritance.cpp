#include <iostream>
using namespace std;
// bottom line: constructors are not inherited by sub-classes, but 
// they are called

class machine
{
private:
	int id;
public:
	machine(): id(0) {cout << "Machine no-arg constructor called" << endl;};	
	machine(int id): id(id) {cout << "Machine arg constructor called" << endl;};	
	void info() {cout << "id: " << id << endl;};
};

class vehicle: public machine // if not public, cannot access methods
{
public:
	// error: id is private to machine
	// vehicle(): id(11) {cout << "Vehicle no-arg constructor called" << endl;};
	vehicle() {cout << "Vehicle no-arg constructor called" << endl;};
	
	// can't refer to id directly, because private to machine
	// instead, specify which constructor to call
	vehicle(int id): machine(id) {cout << "Vehicle arg constructor called" << endl;};
};

class car: public vehicle
{
public:
	// can specify which constructor to call
	// here with new default argument
	// can only refer to direct super-classes, e.g. not machine()
	car(): vehicle(99) {cout << "Car no-arg constructor called" << endl;};
};


int main(int argc, char const *argv[])
{
	machine blob;
	vehicle valerie; // calls to both machine() and vehicle()!
	valerie.info(); // id was initialised when machine() was called

	// error: constructor not inherited
	// car charles(123);

	car charly;
	charly.info();
	return 0;
}


