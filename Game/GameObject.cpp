#include "GameObject.hpp"

GameObject::GameObject() {

}

GameObject::GameObject(SDL_Rect rect, SDL_Renderer* renderer)
{
	this->rect = rect;
	this->sprite = new Sprite("avatar.png", renderer);
	this->isMoving = false;
	this->movingX = false;
	this->movingY = false;
}




GameObject::~GameObject()
{
}

void GameObject::moveTo(int x, int y)
{
	this->rect.x = x;
	this->rect.y = y;
}

void GameObject::moveTo(int x, int y, float speed)
{
	this->targetX = x;
	this->targetY = y;
	this->moveSpeed = speed;
	this->isMoving = true;
	this->movingX = true;
	this->movingY = true;

}

SDL_Color GameObject::getColour() {
    return colour;
}

void GameObject::setColour(SDL_Color colour) {
    this->colour = colour;
}

Sprite* GameObject::getSprite()
{
	return this->sprite;
}

SDL_Rect GameObject::getRect()
{
	return this->rect;
}

SDL_Rect GameObject::getRectCenter()
{
	SDL_Rect r;
	r.x = this->rect.x + this->rect.w / 2;
	r.y = this->rect.y + this->rect.h / 2;
	r.w = this->rect.w;
	r.h = this->rect.h;

	return r;

}

bool GameObject::moving()
{
	return isMoving;
}

void GameObject::update()
{


	if (isMoving) {
		if (movingX) {
			if (targetX < getRectCenter().x) {
				if (getRectCenter().x - targetX < moveSpeed) {
					rect.x -= getRectCenter().x - targetX;
					movingX = false;
				}
				else {
					rect.x -= moveSpeed;
				}
			}
			else if (targetX > getRectCenter().x) {

				if (targetX - getRectCenter().x < moveSpeed) {
					rect.x += targetX - getRectCenter().x;
					movingX = false;
				}
				else {
					rect.x += moveSpeed;
				}

			}

		}

		if (movingY) {
			if (targetY < getRectCenter().y) {
				if (getRectCenter().y - targetY < moveSpeed) {
					rect.y -= getRectCenter().y - targetY;
					movingY = false;
				}
				else {
					rect.y -= moveSpeed;
				}


			}
			else if (targetY > getRectCenter().y) {
				if (targetY - getRectCenter().y < moveSpeed) {
					rect.y += targetY - getRectCenter().y;
					movingY = false;
				}
				else {
					rect.y += moveSpeed;
				}

			}
		}

		if (!movingX && !movingY) {
			isMoving = false;
		}


	}
}


