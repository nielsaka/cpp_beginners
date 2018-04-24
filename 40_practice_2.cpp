#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	for (int i = 1; i < 1001; ++i)
	{
		if (i % 100 == 0) cout << "." << flush;
	}
	cout << endl;
	return 0;
}