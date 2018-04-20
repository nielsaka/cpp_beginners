#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char text[] = "hello";


	int n_char = sizeof(text) - 1;

	char* p_start = text;
	char* p_end = p_start + n_char - 1;

	while (p_start < p_end) { // TODO: use cout to follow logic
		char save = *p_start;
		*p_start = *p_end;
		*p_end   = save;

		p_start++;
		p_end--;
	}

	cout << text << endl;

	return 0;
}