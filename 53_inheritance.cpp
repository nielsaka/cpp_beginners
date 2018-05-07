#include <iostream>
using namespace std;

// generic animal
class animal
{
public:
	void speak() {cout << "My nose is red" << endl;}
	
};

// more specific animal
// type of animal -> cat is a sub-class of super-class animal
class cat: public animal // <----- Important line
{
public:
	void jump() {cout << "cat is jumping" << endl;}
};

// always useful when faced with a hierarchy
// machines -> cars -> volkswagen -> polo
// living being -> plant -> tree -> apple tree

int main(int argc, char const *argv[])
{
	animal rudolf;
	rudolf.speak();

	cat theodore;
	theodore.speak();
	theodore.jump();
	
	return 0;
}