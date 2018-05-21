#include <iostream>
#include <SDL.h>
using namespace std;


int main(int argc, char const *argv[])
{
	// constant variable for window size
	// could also put as static public variables in class
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 1200; 
	cout << "Hello World!" << endl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	SDL_Window *window = SDL_CreateWindow("Hello Word", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
		SDL_WINDOW_SHOWN);

	// can't create window?
	if (window == NULL) {
		SDL_Quit();
		printf("Could not create window: %s\n", SDL_GetError());
		return 2;
	}

	// game loop: trying to update everything as often as possible
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		// 1. Update particles

		// 2. Draw particles

		// 3. check for messages/events

		// SDL offers convenience function writing in event
		// --> just supply address; side-effect!?
		while (SDL_PollEvent(&event)) {
			// new language element: "struct"
			// like a class, but can access all member variables and methods
			// no definition of private/public; 
			// breaks encapsulation, but increases efficiency
			if (event.type == SDL_Quit) quit = true;
		}
	}

	// close and clean up resources
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

/*

let compiler know location of library header files. on my machine:

g++ -I/usr/include/SDL2/ 58_particle_fire_explosion.cpp -lSDL2

the order of options is important! "-lSDL2" must be after .cpp file
why? what does -I and -l stand for? syntax of g++ command?
<

*/