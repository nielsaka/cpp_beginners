#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string text = "hello"; 

	cout << text << endl;

	// alternatively
	char text2[] = {'h', 'e', 'l', 'l', 'o'};
	
	// won't work:
	// char text2[] = {"h", 'e', 'l', 'l', 'o'};
	cout << text2 << endl;

	//alternatively 
	char text3[] = {"hello"};
	cout << text3 << endl;

	cout << "================" << endl;

	// BUT
	for (int i = 0; i < sizeof(text3); ++i)
	{
		cout << i << " " << text3[i] << endl;
	}

	// sizeof(text3) is actually 6 !

	cout << "================" << endl;

	// last entry is the null string terminator (a zero)
	// -> invisible character in string
	// useful for finding out when string stops
	for (int i = 0; i < sizeof(text3); ++i)
	{
		cout << i << " " << (int)text3[i] << endl;
	}

	cout << "================" << endl;

	int k = 0;
	while (true) {
		cout << text[k] << flush;
		k++;
		if ((int)text[k] == 0) break;
	}
	cout << endl;

	return 0;
}

/* 

practice: 

create char string and output it
output with for loop
outptu with while(true) loop

*/