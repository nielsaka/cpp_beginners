#include <iostream>

using namespace std;

class Train
{
private:
	string name;
public:
	Train() {cout << "Tuutuut!" << endl;};
	Train(string name):name(name) {cout << "Zug is da" << endl;};
	~Train() {cout << "Zug kaputt" << endl;};

	void set_name(string name) {this->name = name;};

	void tufftuff() {
		cout << "Die " <<
		name << " ist da!" <<
		endl;};
};


int main(int argc, char const *argv[])
{
	Train* agilis = new Train("ag1515");
	agilis->tufftuff();

	delete agilis;

	Train* zugsammlung = new Train[26];

	// TODO: how to measure number of objects?
	// pointer does not know how many more are comming...?!
	// is there a 'next' somewhere that would point to NULL?
	// could implement in while() loop?
	// Difficult! arrays aren't "objects or structures"; don't
	// have length stored somewhere; also, indexing e.g. arr[11], 
	// is similar (equal?) to *(arr+11) -> can always move pointer 
	// ahead; simply non-sensical.
	// Instead, work with std::vector or std:array (c++11)

	// does not work with pointers!
	// double num_trains = sizeof(zugsammlung) / sizeof(*zugsammlung);
	
	cout << sizeof(*zugsammlung) << endl; // size of Train (?)
	cout << sizeof(zugsammlung) << endl; // size of pointer (?)

	char ch = 'A';
	for (int i = 0; i < 26; ++i, ++ch)
	{
		// convert to string first, set_name() expects string
		// here, need to specify number of repetitions of char
		// std::string has a constructor matching these argumernts
		// (also has others; documentation?)
		string name(1, ch);
		

		// no need to de-reference 'zugsammlung[1]'
		zugsammlung[i].set_name(name); 
		zugsammlung[i].tufftuff();
	}
	delete [] zugsammlung;

	// no error message ?!?
	zugsammlung[100].tufftuff();

	int age[10] = {};

	// again, no error message
	cout << age[11] << endl;

	return 0;
}