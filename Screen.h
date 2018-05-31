#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h> 

namespace cop {
// class skeleton
class Screen {
public:
	// public, so they are accessible from outside
	// static, so they are shared across instances
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 1200; 
	
private:
	// prefix with m_ to mark as instance variables, not local
	SDL_Window *m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;

public:
	 // constructor
	Screen();

	bool init();
	bool processEvents();
	void close();
};
	
}

#endif