#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string text[] = {"duck", "window", "night sky"};


	// why does this return 3, even though the strings are 
	// of different length? Actual text is elsewhere; just  
	// working with pointers
	double len_text = sizeof(text) / sizeof(string);

	cout << len_text << endl;

	for (int i = 0; i < len_text; ++i)
	{
		cout << text[i] << endl;
	}


	// arrays working extremly similar to pointers
	// array knows how much data it is pointing at

	string* p_text = text; // pointing to first element

	// p_text does not know how many other strings follow
	// text does know

	// can cycle through pointers again (??)

	for (int i = 0; i < len_text; ++i)
	{
		cout << p_text[i] << endl;
	}


	cout << "=========================" << endl;
	// alternatively, de-reference pointer

	cout << *p_text << endl;

	// move to next bit of data
	p_text += 1;
	cout << *p_text << endl; 

	// in for loop
	p_text = text;
	for (int i = 0; i < len_text; ++i, p_text++)
	{
		cout << *p_text << " " << flush;
	}
	cout << endl;

	// ++i vs i++ ? order of evaluation?

	string* p_elem = &text[0];
	string* p_end  = &text[2];

	// or 

	string* p_end2 = &(text[2]); // but [ higher precedence over &

	cout << "=========================" << endl;

	while(true) {
		cout << *p_elem << " " << flush;
		if (p_elem == p_end) break;
		p_elem++;
	}

	return 0;
}

/* 

TODO: exercises - loop through array using pointers
i)  array style
ii) increment pointer
iii) comparison of current and end


*/