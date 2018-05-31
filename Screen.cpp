#include "Screen.h"

// namespace useful for avoiding name collision
// otherwise would have to make sure that variable and class
// names are not too common
namespace cop {


// constructor with constructor initialisation list
Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}
bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Hello Word", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
		SDL_WINDOW_SHOWN);

	// can't create window?
	if (m_window == NULL) {
		SDL_Quit();
		printf("Could not create window: %s\n", SDL_GetError());
		return false;
	}

	// each pixel 32 bits: Red, Green, Blue each one byte and Alpha one byte
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		//cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	if (m_texture == NULL) {
		//cout << "Could not create texture" << endl;
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_Quit();
		return false;
	}

	// type Uint32 defined by SDL
	// int could _not_ be 32 bits on some systems!
	// need enough for all pixels on screen
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	// What if allocation of buffer fails? either return NULL or exception thrown
	// --> ideally, would have to deal with it; catch it / check for it. 
	
	// screen will be random! data in buffer completely at random
	// instead, write something to buffer

	// memset really efficient function for setting values of 
	// bunch of bits
	memset(m_buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// R = 255, G = 255, B = 255 -> white
	
	// hexadecimal
	// in c++, Ox indicates that hexadecimal number will follow
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// advantage of hexadecimal: two digits = one byte;
	// easy to read in RGB system; each color two digits e.g. FF00FF

	// setting 32000 to 32003 to FF? 8 * 4 = 32 bits -> Uint32
	m_buffer[32000] = 0xFFFFFFFF; // which colour is which byte?

	/*
	// same as memset(), but slower
	// potentially more flexible; memset() just one value
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
	{
		m_buffer[i] = 0xFFFFFFFF;
	}
	*/

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
	{
		// experiment
		m_buffer[i] = 0xFFFF0000; // 0xRedGreenBlueAlpha
	}

	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	return true;
}
bool Screen::processEvents() {
	return false;
}
void Screen::close() {

	// close and clean up resources
	delete[] m_buffer;

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

}