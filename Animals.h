#ifndef ANIMALS_H_
#define ANIMAL_H_

using namespace std;

namespace animals {

	const string WORLD = "earth";

	class Cat
	{
	public:
		void speak() {cout << "Cat from namespace 'animals' here" << endl;};
		//Cat();
		//~Cat();
		
	};

}

#endif