#pragma once


#include <stdio.h>
#include "SDL.h"
#include "Sprite.hpp"

class GameObject {

public:
	GameObject();
	GameObject(SDL_Rect * rect, SDL_Renderer * renderer);
	
	~GameObject();
	
	void moveTo(int x, int y);
	Sprite* getSprite();
	SDL_Rect* getRect();

private:
	SDL_Rect *rect;
	Sprite *sprite;

};
