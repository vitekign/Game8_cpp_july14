#include "Sprite.h"
 

Sprite::Sprite( DrawEngine *engine, const Level *level,
	int numSprite, int x, int y, int numLives) : level(level), engine(engine)
{
	pos.x = x; 
	pos.y = y; 
	sprite = numSprite; 
	this->numLives = numLives; 


	moveAndDraw(0, 0); 
}


bool Sprite::isMoveLegal(int x, int y)
{
	if (level->map[x][y] == app::EMPTY_WALL)
		return true; 
	return false; 
}

bool Sprite::moveAndDraw(float x, float y)
{
	float i = pos.x + x;
	float j = pos.y + y;
	if (isMoveLegal(i, j))
	{
		eraseSprite(pos.x, pos.y); 

		pos.x += x; 
		pos.y += y; 
		engine->gotoXY(pos.x, pos.y); 
		engine->drawSprite(sprite, pos.x, pos.y); 

		return true; 
	}
	return false; 
}


void Sprite::eraseSprite(int x, int y)
{
	engine->eraseSprite(x, y); 
}

app::vector Sprite::getPos(void)
{
	return pos; 
}

bool Sprite::isAlive(void)
{
	return numLives > 0; 
}

void Sprite::idleUpdate(void)
{

}

int Sprite::getX(void)
{
	return pos.x; 
}

int Sprite::getY(void)
{
	return pos.y; 
}

void Sprite::addLives(int num)
{
	numLives += num; 
}