#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "Screen.h"

using namespace cop;
using namespace std;

int main(int argc, char const *argv[])
{
	
	// set seed of RNG
	// different every time (haha)
	srand(time(NULL));

	Screen screen; // initialise/construct object
	if(!screen.init()) cout << "Error initiatlising SDL" << endl; 

	Swarm swarm;

	// game loop: trying to update everything as often as possible
	bool quit = false;
	int max = 0;
	while (!quit) {
		// 1. Update particles

		// 2. Draw particles
		int elapsed = SDL_GetTicks();

		//screen.clear();

		// instead of clearing screen, will blurr screen
		swarm.update(elapsed);

		//why unsigned char?
		// just making sure that values are between 0 and 255
		// because unsigned char cannot take other values
		// e.g. if RHS is 256 then result is 1 (or something like that?)
		// C++ implicitly converts type! RHS is double, LHS is unsigned char
		unsigned char red   = (1 + sin(elapsed * 0.0001)) * 128;
		// but can also be more explicit and cast type.
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue  = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		//TODO: check out const .. const again
		const Particle* const pParticles = swarm.get_particles();

		for (int i = 0; i < Swarm::NPARTICLES; ++i)
		{
			Particle particle = pParticles[i]; // is it a pointer or not?

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2; // why transform back and forth?
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}
		screen.boxBlur();
		screen.update();
		// 3. check for messages/events
		quit = !screen.processEvents();
	}
	screen.close();
	return 0;
}

/*

let compiler know location of library header files. on my machine:

g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp -lSDL2
g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp Screen.h Screen.cpp -lSDL2
g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp Screen.h Screen.cpp Particle.cpp Particle.h -lSDL2
g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp Screen.h Screen.cpp Particle.cpp Particle.h Swarm.h Swarm.cpp -lSDL2

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