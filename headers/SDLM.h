#ifndef SDLM_H
#define SDLM_H

#include <SDL2/SDL.h>
#include <thread>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

namespace sdlm
{
	extern void (*pFun)(void);
	extern void (*rFun)(void);
	extern SDL_Window *window;
	extern SDL_Surface *screenSurface;
	extern SDL_Event event;
	extern bool running;


	extern void INIT();
	extern void LOOP();
	extern void INP_THREAD();
	extern void KILL();
}

void __attribute__((constructor)) sdlm::INIT(); 
void __attribute__((destructor)) sdlm::KILL(); 



#endif