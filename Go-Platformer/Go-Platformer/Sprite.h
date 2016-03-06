#include "stdfx.h"
class Sprite
{
public:
	Sprite(SDL_Renderer* passed_renderer, std::string filePath, SDL_Rect* posRec, SDL_Rect* playerPos, int xp, int yp, int wp, int hp, int xr, int yr, int wr, int hr, int* width, int* height, int* frameWidth, int* frameHeight);
	Sprite(SDL_Renderer* passed_renderer, std::string filePath, SDL_Rect* grass);
	~Sprite();
	void Draw(SDL_Rect* player, SDL_Rect* Rec);
	//void RectSetup(SDL_Rect* rect, int x, int y, int w, int h);
	SDL_Texture* GetImage(){
		return image;
	}
private:
	SDL_Texture* image;
	SDL_Rect player;
	SDL_Surface* img;
	SDL_Rect Rec;
	SDL_Renderer* renderer;
	SDL_Rect grass;
	std::string filePath;
	int xp, yp, wp, hp;
	int xr, yr, wr, hr;
	int width, height;
	int* frameWidth, frameHeight;
};