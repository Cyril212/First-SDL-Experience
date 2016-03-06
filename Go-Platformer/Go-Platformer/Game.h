#include "stdfx.h"
#include "Sprite.h"
class Game
{
public:
	Game(int passed_screenWidth,int passed_screenHeight);
	~Game();
	void GameLoop();
	void getTime();
	void aPerFrame();
	void mainControl();
	void jump();
private:
	bool onGround;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
	bool quit;
	int screenWidth;
	int screenHeight;
	Sprite* sprite;
	Sprite* background;
	SDL_Texture* grass_image;
	SDL_Rect grass_rect;
	SDL_Rect playerRect;
	int frameWidth, frameHeight,textureWidth,textureHeight;
	const int FPS = 60;
	float frameTime;
	int prevTime;
	int currentTime;
	float deltaTime;
	float moveSpeed;
	const Uint8 *keyState;
	SDL_Rect playerPosition;
	bool isMove;
	int count = 0;
	const Uint8 *prevKeyState;
	const int ground = 400;
	float dx, dy = 0.1;
	bool wasPress;
    

};