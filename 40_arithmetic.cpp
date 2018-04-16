#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// watch out in division
	double val_1 = 7/2;
	cout << "7/2 = " << val_1 << endl;

	//better
	val_1 = 7.0 / 2;
	cout << "7.0/2 = " << val_1 << endl;

	//even better: cast variable type
	int some_val = 7;
	val_1 = (double)some_val / 2;
	cout << "7.0/2 = " << val_1 << endl;

	//+= and ++
	int val_2 = 8;
	val_2 += 1; // 9
	cout << "val 2 = " << val_2 << endl;
	val_2 ++; // 10
	cout << "val 2 = " << val_2 << endl;
	val_2 --; // 9
	cout << "val 2 = " << val_2 << endl;
	val_2 /= 5; // 1
	cout << "val 2 = " << val_2 << endl;
	val_2 *= 15; // 15
	cout << "val 2 = " << val_2 << endl;

	// modulus
	val_2 = 13%5; //remainder of 13 divided by 5 is 3
	cout << "val 2 = " << val_2 << endl;


	// precedence 
	// * and / over + and -
	// left to right

	// better, use brackets - e.g % vs * ?

	
	return 0;
}

/*

TODO: exercises from video (minute 12:00 ff)

*/