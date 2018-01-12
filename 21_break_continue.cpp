#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	for (int i = 0; i < 5; ++i)
	{
		cout << "i is " << i << "\n";

		break; // will jump out of loop immediately
	}


	for (int j = 0; j < 5; ++j)
	{
		if (j == 3) continue; // will jump to next iteration
		cout << "j is " << j << "\n";
		
	}
	*/


	// Same example as with do{ } while();
	// but now using break; 

	const string password = "hello";
	string input;

	// here do{} while(); is actually useful, because first
	// iteration will always be executed!

	// no, can also use while(true) {... break;}

	/*
	do {
		cout << "Enter your password >" << flush;
		cin >> input;

		if (input == password) {
			break;
		}
		cout << "Access denied." << endl;
	} while(true);
	*/


	// Same example as with do{ } while();
	// but now using continue; 

	// not really very nice...?

	do {
		cout << "Enter your password >" << flush;
		cin >> input;

		if (input != password) {
			cout << "Access denied." << endl;
			continue;
		}
		break;
	} while(true);

	cout << "Password accepted" << endl;

	cout << "Program quitting..." << endl;

	return 0;
}




