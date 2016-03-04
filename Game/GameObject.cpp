#include "GameObject.hpp"

GameObject::GameObject() {

}

GameObject::GameObject(SDL_Rect *rect, SDL_Renderer* renderer)
{
	this->rect = rect;
	this->sprite = new Sprite("avatar.png", renderer);
}




GameObject::~GameObject()
{
}

void GameObject::moveTo(int x, int y)
{
	this->rect->x = x;
	this->rect->y = y;
}

Sprite* GameObject::getSprite()
{
	return this->sprite;
}

SDL_Rect* GameObject::getRect()
{
	return this->rect;
}

bool GameObject::moving()
{
	return isMoving;
}


