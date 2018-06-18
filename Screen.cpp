#include "Screen.h"

// namespace useful for avoiding name collision
// otherwise would have to make sure that variable and class
// names are not too common
namespace cop {


// constructor with constructor initialisation list
Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

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
	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	// What if allocation of buffer fails? either return NULL or exception thrown
	// --> ideally, would have to deal with it; catch it / check for it. 
	
	// screen will be random! data in buffer completely at random
	// instead, write something to buffer

	// memset really efficient function for setting values of 
	// bunch of bits
	memset(m_buffer1, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// R = 255, G = 255, B = 255 -> white
	
	// hexadecimal
	// in c++, Ox indicates that hexadecimal number will follow
	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// advantage of hexadecimal: two digits = one byte;
	// easy to read in RGB system; each color two digits e.g. FF00FF

	// setting 32000 to 32003 to FF? 8 * 4 = 32 bits -> Uint32
	m_buffer1[32000] = 0xFFFFFFFF; // which colour is which byte?

	/*
	// same as memset(), but slower
	// potentially more flexible; memset() just one value
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
	{
		m_buffer1[i] = 0xFFFFFFFF;
	}
	*/

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
	{
		// experiment
		m_buffer1[i] = 0x00000000; // 0xRedGreenBlueAlpha
		m_buffer2[i] = 0x00000000; // 0xRedGreenBlueAlpha
	}

	return true;
}

// Uint8: unsigned 8 bit int (~like a char)
// why use special type, e.g. Uint32? It is going to be the same on all platforms!
// int and char could have different number of bytes on different platform / os.

// need to declare types of arguments again?
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	// check that not off screen
	// inefficient to have to check here; for more efficient programming, make sure elsewhere?
	// have to check a lot of pixels
	// but nowadays enough computing power to be able to not care
	if (x < 0 || x > SCREEN_WIDTH - 1 || y < 0 || y > SCREEN_HEIGHT - 1) return ;

	// want to combine red, blue, green, alpha to a specific colour
	// char is 1 byte; unsigned int 4 bytes.
	// But here will use Uint32 instead (see above)
	
	// declare and assign
	Uint32 colour = 0;

	// set colour
	colour += red;
	colour <<= 8;
	colour +=green;
	colour <<= 8;
	colour +=blue;
	colour <<= 8;
	colour += 0xFF; // alpha? opaque!

	// structure of m_buffer? m_buffer just a one-dimensional array (like a long vector!)
	// y: height
	// x: width
	// first 800 entries correspond to the first row (top/bottom?)
	// second 800 entries to the second row, etc.
	// navigate to the correct height by going through all the rows (y * SCREEN_WIDTH),
	// then navigate to the correct width by adding x columns.
	// both start counting at zero!
	m_buffer1[(y * SCREEN_WIDTH) + x] = colour; 
	//m_buffer2[(y * SCREEN_WIDTH) + x] = colour; 
}

//draw screen again
void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

/*
void Screen::clear() {
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}
*/

void Screen::boxBlur() {

	// blur (first try)
	/*
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
	{
		// change only the alpha?
		int alpha = m_buffer2[i] & 0x000000FF;
		int rgb   = m_buffer2[i] & 0xFFFFFF00;
		m_buffer2[i] = rgb * 0.09 + alpha * 0.09;
	}
	*/

	//switch buffer1 and buffer2
	// nice feature: not copying all the values, but just installing additional pointer
	// (which, assumably is fairly cheap?)
	Uint32* temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y = 0; y < SCREEN_HEIGHT; ++y)
	{
		for (int x = 0; x < SCREEN_WIDTH; ++x)
		{
			int red_total = 0;
			int green_total = 0;
			int blue_total = 0;
			// average pixels surrounding current pixel
			for (int row = -1; row <= 1; ++row)
			{
				for (int col = -1; col <= 1; ++col)
				{
					int x_pix = x + col;
					int y_pix = y + row;

					if (
						x_pix >= 0 &&
						x_pix < SCREEN_WIDTH &&
						y_pix >= 0 &&
						y_pix < SCREEN_HEIGHT
						) {
						Uint32 rgb = m_buffer2[y_pix * SCREEN_WIDTH + x_pix];

						// add red, green and blue components
						Uint8 red   = rgb >> 24;
						Uint8 green = rgb >> 16;
						Uint8 blue  = rgb >> 8;

						red_total += red;
						green_total += green;
						blue_total += blue;
					}
				}
			}
			// re-declare since not in scope of for loop above (try things...?)
			Uint8 red = red_total / 9;
			Uint8 green = green_total / 9;
			Uint8 blue = blue_total / 9;

			setPixel(x, y, red, green, blue);
		}
	}
}

bool Screen::processEvents() {
	SDL_Event event;
	// SDL offers convenience function writing in event
	// --> just supply address; side-effect!?
	while (SDL_PollEvent(&event)) {
		// new language element: "struct"
		// like a class, but can access all member variables and methods
		// no definition of private/public; 
		// breaks encapsulation, but increases efficiency
		if (event.type == SDL_QUIT) return false;
	}
	return true;
}

void Screen::close() {

	// close and clean up resources
	delete[] m_buffer1;
	delete[] m_buffer2;

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

}