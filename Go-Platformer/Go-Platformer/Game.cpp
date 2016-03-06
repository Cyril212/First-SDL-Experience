#include "Game.h"
Game::Game(int passed_screenWidth, int passed_screenHeight)
{
	wasPress = false;
	count = 0;
	isMove = false;
	frameTime = 0;
	prevTime = 0;
	currentTime = 0;
	deltaTime = 0;
	moveSpeed = 600.0f;
	quit = false;
	screenWidth = passed_screenWidth;
	screenHeight = passed_screenHeight;
	window = NULL;
	renderer = NULL;
	window = SDL_CreateWindow("Little Wind", 50, 50, passed_screenWidth, passed_screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	mainEvent = new SDL_Event();
	sprite = new Sprite(renderer, "img/image.png", &playerPosition, &playerRect, 0, 0, 64, 64, 0, 0, 32, 32,&textureWidth,&textureHeight,&frameWidth,&frameHeight);
	background = new Sprite(renderer,"img/gr.png",&grass_rect);
	//SDL_QueryTexture(sprite->GetImage(), NULL, NULL, &textureWidth, &textureHeight);
	
}
Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}
void Game::getTime()
{
	onGround = true;
	prevTime = currentTime;
	currentTime = SDL_GetTicks();
	deltaTime = (currentTime - prevTime) / 1000.0f;
	frameTime += deltaTime;
	keyState = SDL_GetKeyboardState(NULL);
	std::cout << "" << deltaTime << std::endl;
}
void Game::aPerFrame()
{
	if (frameTime >= 0.15f && isMove)
	{
		
		frameTime = 0;
		playerRect.x += frameWidth;
		std::cout << "x:" << playerRect.x << std::endl;
		if (playerRect.x >= textureWidth)
			playerRect.x = 0;
	}
}
void Game::mainControl()
{
	/*std::cout << "x:" << playerPosition.x << std::endl;
	std::cout << "y:" << playerPosition.y << std::endl;*/
	if (playerPosition.y < ground){	
			onGround = false;
			playerPosition.y += moveSpeed * deltaTime;
			
	}
	if (keyState[SDL_KEYUP])
	{
		isMove = false;

	}
	if (keyState[SDL_SCANCODE_RIGHT])
	{
		isMove = true;
		if (keyState[SDL_KEYDOWN] && keyState[SDL_SCANCODE_RIGHT])
		{
			playerRect.x = 0;
		}
		playerRect.y = 64;
		playerPosition.x += moveSpeed * deltaTime;
	}

	if (keyState[SDL_SCANCODE_LEFT]){
		isMove = true;
		if (keyState[SDL_KEYDOWN] && keyState[SDL_SCANCODE_LEFT])
		{
			playerRect.x = 0;
		}
		playerRect.y = 32;
		playerPosition.x -= moveSpeed * deltaTime;
	}
	

	if (keyState[SDL_SCANCODE_UP] && onGround)
	{
		wasPress = true;
	}
	jump();
}
void Game::jump()
{
	if (wasPress && playerPosition.y > 300)
	{
		playerPosition.y -= 1500.0f * deltaTime;
	}
	else
	{
		wasPress = false;
	}
}
void Game::GameLoop()
{

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		getTime();
		aPerFrame();
		mainControl();
		SDL_PollEvent(mainEvent);

		SDL_RenderClear(renderer);
		background->Draw(&grass_rect, NULL);
		sprite->Draw(&playerRect,&playerPosition);
		
		SDL_RenderPresent(renderer);

	}
}
