#include <iostream>
#include <SDL.h>
using namespace std;


int main(int argc, char const *argv[])
{
	cout << "Hello World!" << endl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	cout << "Success" << endl;

	SDL_Quit();

	return 0;
}

/*

let compiler know location of library header files. on my machine:

g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp -lSDL2

the order of options is important! "-lSDL2" must be after .cpp file
why? what does -I and -l stand for? syntax of g++ command?


*/