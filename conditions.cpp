// in sublime
// I can comment 
// a block of text
// by pressing 
// ctrl+shift+c


/*
but unfortunately, it will always
comment using backslashes

unless I change the keybinding in sublime ...
*/


/*
*	this is another way to comment
*	but unfortunately, sublime does not prefix
	the next line with a * when I hit enter

	it is not necessary either, though
*/


#include <iostream>
using namespace std;

int main() {
	// && & || |

	// I am speculating here!

	// && vs. &
	// logical and vs. bitwise and (correct names?)

	// || vs. |
	// logical or vs. bitwise or (correct names?) 

	// && operates on objects of type bool (?)
	// and returns an object of type bool (?)


	// & operates on single bits (?); so: 
	// 1010 & 1001 = 1000 (?)
	// 1010 | 1001 = 1011 (?)


	int a = 10;
	int b = 9;

	cout << (a & b) << "\n"; // 1000 = 8 
	cout << (a | b) << "\n"; // 1011 = 11

	char x = 'h'; 
	char y = 'w';

	cout << (x & y) << "\n";

	wchar_t h = 'h';
	wchar_t w = 'w';

	cout << "ASCII code for letter 'h': " << h << endl;
	cout << "ASCII code for letter 'w': " << w << endl;

	// 104 = 64 + 32 + 8 = 1101000
	// 119 = 64 + 32 + 16 + 4 + 2 + 1 = 1110111

	// 1101000 & 1110111 = 1100000 = 96
	// 1101000 | 1110111 = 1111111 = 127

	cout << (h & w) << "\n"; // 96 
	cout << (h | w) << "\n"; // 127

	// YES!

	// what kind of types do & and | accept?

	/*-----------------------------------------------------------------------*/
	/* Precedence */ 
	/*-----------------------------------------------------------------------*/

	// expressions is evaluated from left to right
	// but if commutative and associative, does not matter...!
	// except perhaps when dealing with negations ?

	if (true || false && true) {
		cout << "condition 1: true\n";
	} else {
		cout << "condition 1: false\n";
	}

	// brackets may help readability

	// it's associative? 
	// exclusively && or || definitely is
	// when && and || are mixed, I think it is as well 
	// 		-> isomorphic to *1 and +0 ... !

	// ... and it is commutative! (says the internet)

	// but !() is not distributive for &&

	if (!(false && true)) {
		cout << "condition 2: true\n";
	} else {
		cout << "condition 2: false\n";
	}

	if (!false && !true)  {
		cout << "condition 3: negation is distributive for && \n";
	} else {
		cout << "condition 3: negation is not distributive for &&\n";
	}


	// in any case, code more comprehensible when
	// conditions are broken up into pieces

	bool cond_1 = (a <= 20) && (b >= 8);
	bool cond_2 = false;

	if (cond_1 || cond_2) {
		cout << "success\n";
	}

	// decimal 0 = 0000 0000 binary
	// decimal 1 = 0000 0001 binary

	// so & and && the same when dealing with bool?? Why have both?

	// maybe to clarify intention, meaning?
	// maybe different results depending on types?

		if (cond_1 | cond_2) {
		cout << "also success\n";
	}
}