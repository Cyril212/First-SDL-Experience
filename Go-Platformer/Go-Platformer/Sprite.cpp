#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* passed_renderer, std::string filePath, SDL_Rect* posRec, SDL_Rect* playerPos, int xp, int yp, int wp, int hp, int xr, int yr, int wr, int hr, int* width, int* height,int* frameWidth,int* frameHeight)
{
	image = NULL;
	renderer = passed_renderer;
	image = IMG_LoadTexture(renderer, filePath.c_str());
	posRec->x = xp;
	posRec->y = yp;
	posRec->w = wp;
	posRec->h = hp;
	playerPos->x = xr;
	playerPos->y = yr;
	playerPos->w = wr;
	playerPos->h = hr;
	SDL_QueryTexture(image, NULL, NULL, width, height);
	*frameWidth = *width / 3;
	*frameHeight = *height / 4;
	
	
}
Sprite::Sprite(SDL_Renderer* passed_renderer, std::string filePath, SDL_Rect* grass)
{
	renderer = passed_renderer;
	image = IMG_LoadTexture(renderer, filePath.c_str());
	grass->x = 0;
	grass->y = 0;
	grass->w =1000;
	grass->h = 700;

}
Sprite::~Sprite()
{
	delete image;
}

void Sprite::Draw(SDL_Rect* posrec, SDL_Rect* playerPos)
{
	SDL_RenderCopy(renderer, image, posrec ,playerPos);
}