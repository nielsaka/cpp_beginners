#include <iostream> // necessary for type string
#include <sstream> // concatenate int and string

using namespace std;

int main(int argc, char const *argv[])
{
	string name = "bob";
	int age = 32;

	// combine name and age in single string
	// combine objects of type string and int

	// first try
	
	// string info = "Name: " + name + "; age: " + age;
	
	// fails, cannot concatenate an int with a string
	// no implicit type conversion; sign of 'strong typing'?

	stringstream ss;

	// streams: "streams of data" - to get data from or move data to
	// cout is also a stream "console output stream" 

	// can use "put-to" operator again: <<
	ss << "Name is: ";
	ss << name;
	ss << "; age is: ";
	ss << age;

	// need to convert to fixed(?) string
	string info = ss.str();

	// now, we can output to console
	cout << info << endl;

	return 0;
}

/*
What else is sstream and stringstream for?
Which object types can I feed to stringstream?
Which object types can a stringstream be converted to?
*/
