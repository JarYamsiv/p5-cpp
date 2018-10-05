#include "../headers/SDLM.h"
#include <stdio.h>

namespace sdlm
{
	void (*pFun)(void);
	void (*rFun)(void);
	SDL_Window *window;
	SDL_Surface *screenSurface;
	bool running;
	SDL_Event event;
}

void sdlm::INIT()
{
	pFun=NULL;
	rFun=NULL;
	if(pFun==NULL)printf("functions initialsed to NULL\n");
	printf("sdlm initialsising\n");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(
							"SDL Tutorial", 
							SDL_WINDOWPOS_UNDEFINED, 
							SDL_WINDOWPOS_UNDEFINED, 
							SCREEN_WIDTH, 
							SCREEN_HEIGHT, 
							SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	running = true;
}

void sdlm::KILL()
{
	running = false;
	printf("sdlm killing\n");
	SDL_DestroyWindow( window ); 
	//Quit SDL subsystems 
	SDL_Quit(); 
}

void sdlm::LOOP()
{
	pFun();
	rFun();
	screenSurface = SDL_GetWindowSurface( window ); 
	//Fill the surface white 
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); 
	//Update the surface 
	SDL_UpdateWindowSurface( window ); 
	//Wait two seconds 
	running = true;
    std::thread evntloop(INP_THREAD);
    while (running)
    {   
        SDL_UpdateWindowSurface(window);
    }
    evntloop.join();
}

void sdlm::INP_THREAD()
{
	while (running)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
            break;
        }
    }
}