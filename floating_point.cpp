#include <iostream>
#include <iomanip> // manipulate input and output (setprecision, fixed, ..)

int main() {

	int i_value = 75.99;
	float f_value = 75.99;

	std::cout << "int value: " << i_value << std::endl; // 75
	std::cout << "float value: " << f_value << std::endl; // 75.99


	// avoid scientific notation
	std::cout << std::fixed << "'Fixed' float value: " << f_value << std::endl;
	// 75.989998 <- not precise because memory always limited
	// "after six or seven digits [at most] ... just garbage"
	std::cout << "float has " << sizeof(float) << " bytes." << std::endl;

	std::cout << std::setprecision(20) << std::fixed
	 << "Float with 20 digits: " << f_value << std::endl;

	// use scientific notation
	std::cout << std::scientific << "'Scientific' float value: " <<
	 f_value << std::endl; // still used 20 digits!


	 // double //
	 ////////////
	 std::cout << std::endl;

	double d_value = 75.99;

	// better, but still not correct
	std::cout << "double value: " << d_value << std::endl;
	std::cout << "double has " << sizeof(double) << " bytes." << std::endl;


	// long double //
	////////////
	 std::cout << std::endl;

	double ld_value = 75.99;

	// better, but still not correct
	std::cout << "long double value: " << ld_value << std::endl;

	// bytes for float, double, long double ist not necessarily the same
	// depending on c++ compiler and machine
	std::cout << "long double has " << sizeof(long double) << " bytes." << std::endl;

	ld_value = 123.45678987654321;
	std::cout << "long double value: " << ld_value << std::endl;

	return 0;
}