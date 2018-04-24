#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

	double seconds;
	cout << "Please enter the number of seconds: " << flush;
	cin >> seconds;

	// using integer division; 
	// convert explicitly, cast type?
	int hours = seconds / 3600;
	int minutes = (int)(seconds - hours * 3600) / 60;
	int seconds2 = (int)seconds % 60;

	// for performance, would be better to store intermediate
	// value such that remainder can be taken from division?
	
	/*
	hours = seconds / 3600;
	minutes = seconds - hours * 3600;
	seconds2 = minutes % 60;
	minutes /= 60;
	*/

	cout << 
		hours << " hours, " <<
		minutes << " minutes and " <<
		seconds2 << " seconds. " << endl;

	return 0;
}