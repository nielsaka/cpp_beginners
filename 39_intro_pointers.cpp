#include <iostream>
using namespace std;

void manipulate(double value) {
	cout << "2. Value of double in manipulate: " << value << endl;
	value = 10.1;
	cout << "3. Value of double in manipulate: " << value << endl;

}

void manipulate_ref(double *value) {
	cout << "2. Value of double in manipulate: " << *value << endl;
	*value = 10.1;
	cout << "3. Value of double in manipulate: " << *value << endl;

}

void manipulate_ref2(double* pointer) {
	cout << "2. Value of double in manipulate: " << *pointer << endl;
	cout << "Address of variable: " << pointer << endl;
	cout << "Adress of pointer: " << &pointer << endl;
	// de-reference pointer to manipulate contents/target of pointer
	*pointer = 10.1;
	cout << "3. Value of double in manipulate: " << *pointer << endl;

}

int main(int argc, char const *argv[])
{
	
	int val = 8; // allocate memory; amount of memory determined by type


	//store address of variable "val"; two ways:
	int* p_val = &val;
	int *q_val = &val;

	cout << "Int value: " << val << endl;
	cout << "Pointer to int address: " << p_val << endl;

	// use cases

	// 1. get value back / dereference
	cout << "Int value via pointer: " << *p_val << endl;

	cout << "=======================" << endl;

	// track down variable state / copy-semantics
	double d_val = 919.2;

	cout << "1. dValue: " << d_val << endl;
	manipulate(d_val);
	cout << "4. dValue: " << d_val << endl;

	cout << "=======================" << endl;

	double e_val = 181.5;

	cout << "1. dValue: " << e_val << endl;
	manipulate_ref2(&e_val);
	// have changed the original variable!
	cout << "4. dValue: " << e_val << endl; 

	return 0;
}

/*
refer to address:			&var		

de-reference address / 
access value of variable:	*var


Why need "double *value" as argument in manipulate_ref ?
Because we are passing on an address which needs to be
stored in a pointer variable. Hence "double *value".
Now, "value" is the pointer, i.e. a variable storing the address of
what has been referenced in the function's argument, while "*value"
is what it is pointing to: the contents.

---> More intuitive to write:
"double* pointer" instead of "double *value" ??!!
*/