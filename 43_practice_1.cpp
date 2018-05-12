#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char text[] = "text, and more teeeext";
	cout << "output as string" << endl;
	cout << text << endl;

	int len_text = sizeof(text); // one char = one byte
	// includes end-of-(array, string?) character
	cout << "size of of char array: " << len_text << endl;
	cout << "\noutput in foor loop:" << endl;
	for (int i = 0; i < len_text - 1; ++i)
	{
		cout << text[i];	
	}
	cout << endl;

	// equivalent: 
	// char* ptr_text = &text[0];
	char* ptr_text = text;
	
	cout << "\nwhile loop:" << endl;
	while(true) {
		cout << *ptr_text;
		ptr_text++;
		if (*ptr_text == 0) break; // 0 = NULL ?
	}
	cout << endl;

	// reverse string
	cout << "\nreversal:" << endl;

	ptr_text = text;
	char here;
	for (int i = 0; i < (len_text - 1) / 2; ++i)
	{
		here = *(ptr_text + i);
		*(ptr_text + i) = *(ptr_text + len_text - 2 - i);
		*(ptr_text + len_text - 2 - i) = here;
	}

	cout << text << endl;
	return 0;
}