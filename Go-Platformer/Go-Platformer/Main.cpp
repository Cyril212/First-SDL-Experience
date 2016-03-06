#include "stdfx.h"
#include "Game.h"
int main(int argc, char *argv[])
{
	/*bool quit = false;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = NULL;
	window = SDL_CreateWindow("Little Wind", 50, 50, 500, 500, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		return 0;
	}

	SDL_Renderer* renderer = NULL;
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event* mainEvent = new SDL_Event();
	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;*/
	Game* game = new Game(600, 600);
	game->GameLoop();
	delete game;
	return 0;
}