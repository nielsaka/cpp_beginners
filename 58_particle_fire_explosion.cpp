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

	// each pixel 32 bits: Red, Green, Blue each one byte and Alpha one byte
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	// TODO: avoid repititon --> refactor code
	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 4;
	}

	// type Uint32 defined by SDL
	// int could _not_ be 32 bits on some systems!
	// need enough for all pixels on screen
	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	// What if allocation of buffer fails? either return NULL or exception thrown
	// --> ideally, would have to deal with it; catch it / check for it. 
	
	// screen will be random! data in buffer completely at random
	// instead, write something to buffer

	// memset really efficient function for setting values of 
	// bunch of bits
	memset(buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// R = 255, G = 255, B = 255 -> white
	
	// hexadecimal
	// in c++, Ox indicates that hexadecimal number will follow
	memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// advantage of hexadecimal: two digits = one byte;
	// easy to read in RGB system; each color two digits e.g. FF00FF

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	
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

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	delete[] buffer;

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