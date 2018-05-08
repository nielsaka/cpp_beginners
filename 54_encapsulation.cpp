#include <iostream>
using namespace std;

class Frog
{
// private data
private:
	// form of encapsulation
	// string is hidden from user
	// can only access via methods
	string name;

	// better to restrict access to data
	// can reason about code more easily
	// document access to data via public methods

// private methods
private:
	string get_name() {return name;};

// public methods
public:
	Frog(string name): name(name) {}; // initialisation list
	void speak() {cout << "my name is " << name << endl;};


	// example: output info, but don't surface get_name() to
	// user directly
	void info() {cout << "My name is still " << get_name() << endl;};

	// make as much of your class as possible private
	// hide the implementation away
	// ==> encapsulate it in a class

	// can have as many private/public sections as wanted in any order
	// but should have some organising principle
private:
	string more_data;

};

int main(int argc, char const *argv[])
{
	Frog Dieter = Frog("Dieter");
	Frog brian("brian"); // implicit call to Frog(string name)
	Dieter.speak();
	brian.speak();
	
	// error
	//cout << brian.get_name() << endl;
	
	brian.info();
	return 0;
}