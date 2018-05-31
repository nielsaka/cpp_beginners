#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace cop;
using namespace std;


int main(int argc, char const *argv[])
{
	
	Screen screen;
	if(!screen.init()) cout << "Error initiatlising SDL" << endl; 

	// game loop: trying to update everything as often as possible
	bool quit = false;
	while (!quit) {
		// 1. Update particles

		// 2. Draw particles

		// 3. check for messages/events
		quit = !screen.processEvents();

	}

	screen.close();

	return 0;
}

/*

let compiler know location of library header files. on my machine:

g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp -lSDL2

the order of options is important! "-lSDL2" must be after .cpp file
why? what does -I and -l stand for? syntax of g++ command?
<

*/

/*

"later on I am going to refactor it and make it more object orientated so that
we don't get into a tangle when we add more and more code to this"

-> at the moment have big main function
could split into smaller functions "c style programming"
instead, (long term) refactor code using classes -> C++ style

*/