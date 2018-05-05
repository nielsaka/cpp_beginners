#include <iostream>
using namespace std;
	
// 'text[]' or 'text[3]' same behaviour
// text[3] reminds user of how many elements are expected
// purely for documentation
void show_1(string text[3]) {

	for (int i = 0; i < 3; ++i)
	{
		cout << text[i] << endl;

	}
	text[0] += " mash"; //changes original array
	cout << sizeof(text) << endl; // 8, same as long; gives warning
	cout << sizeof(long) << endl;
	// size of pointer is 8 (on this machine?)
}
	// good practice, pass on number of elements as const!
void show_2(string text[], const int elem) {
	cout << "----------------------" << endl;
	for (int i = 0; i < elem; ++i)
	{
		cout << text[i] << endl;
	}
	cout << "----------------------" << endl;
}
	// why is it like this? guess: because not the full array is
	// passed on to the function (no copy is made),
	// but just a reference(??)

	// Indeed! passing on pointer just the same behaviour 
	// as passing on array! pointer has no size information.
void show_3(string* text, const int elem) {
	cout << "----------------------" << endl;
	for (int i = 0; i < elem; ++i)
	{
		cout << text[i] << endl;
	}
	cout << sizeof(text) << endl; // 8; same as above

	text[1] += " juice"; // changes original array
	cout << "----------------------" << endl;
}

// alternatively, pass on a reference

// difficulty: string& text[3] is an array of references to strings
// instead, want reference to array of strings
// confusing! figure out on again.

// string(& text)[2] will not work!
void show_4(string(& text)[3]) {
	cout << *(text + 0) << endl;
	cout << text[1] << endl;
	cout << *(text + 2) << endl;

	cout << sizeof(text) << endl; // 96 !

	text[2] = "I don't like " + text[2] + "s"; // changes original array
}

// BAD
// do not return pointer to a local variable
// scope of 'texts' ends at curly brace -> object deleted!
// pointer points to ???
string* get_array() {
	string texts[] = {"palm", "hand", "coco"};

	return texts;
}

// global variable!
string ttt[] = {"palm", "hand", "coco"}; 

// useless
string* get_array_2() {
	return ttt;
}

// with 'new' keyword
string* get_array_3() {
	string* ptr_txt = new string[3];
	ptr_txt[0] = "hello";
	ptr_txt[1] = "world";
	ptr_txt[2] = "again";

	return ptr_txt;
}

void free_mem(string* ptr) {
	delete [] ptr;
}

int main(int argc, char const *argv[])
{
	string text[] = {"apple", "orange", "banana"};
	show_1(text);
	cout << sizeof(text) << endl; // 96

	// problem: lose information of how many elements in array
	// when passing array to function.

	// conventional solution: pass length of array as argument
	show_2(text, sizeof(text) / sizeof(string));
	show_3(text, sizeof(text) / sizeof(string));

	cout << &text << endl;
	show_4(text);

	cout << text[2] << endl;

	string* new_text = get_array(); 

	// cout << *new_text << endl; // BAD! Segmentation fault

	cout << *(get_array_2()+0) << endl;
	cout << *(get_array_2()+1) << endl;
	cout << *(get_array_2()+2) << endl;

	string* ptr_here = get_array_3();

	for (int i = 0; i < 3; ++i)
	{
		cout << ptr_here[i] << " " << flush;
	}
	cout << endl;


	// don't forget to delete!! not ideal since need to know about it
	// don't forget square brackets since it is (some sort of) array
	/*
	 delete [] ptr_here;
	*/

	// common practice to set up utility function for 
	// de-allocation of memory;
	// mention in documentation; user might not how whether it is
	// array or something else (?)
	free_mem(ptr_here);
	return 0;
}

/*

three syntaxes for passing array
1) array with number of elements
2) pointer with number of elements (equal to 1)
3) reference to array

returnin array
* watch out that it is not a pointer to a local variable
* instead, make use of 'new' and return pointer
* can return complete array (deep copy)?

*/