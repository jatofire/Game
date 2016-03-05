#pragma once


#include <stdio.h>
#include "SDL.h"
#include "Sprite.hpp"
#include <math.h>

class GameObject {

public:
	GameObject();
	GameObject(SDL_Rect * rect, SDL_Renderer * renderer);
	
	~GameObject();
	
	void moveTo(int x, int y);
	void moveTo(int x, int y, float speed);
	Sprite* getSprite();
	SDL_Rect* getRect();
	bool moving();

	void update();

private:
	SDL_Rect *rect;
	Sprite *sprite;
	bool isMoving;
	int targetX;
	int targetY;
	float moveSpeed;
	bool movingX;
	bool movingY;
};
