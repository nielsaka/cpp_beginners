#include <iostream>
using namespace std;

int main() {
	std::cout << "Enter your name: " << flush;
	string input;
	std::cin >> input;
	std::cout << "You entered: " << input << endl;

	int value;
	std::cout << "Enter a number: " << flush;
	cin >> value;
	cout << "You entered: " << value << endl;

	return 0;
}