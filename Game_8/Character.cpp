#include "Character.h"




Character::Character(DrawEngine *engine, const Level *level, int numSprite, int x, int y,
	char left_key, char right_key, char down_key, char up_key) 
	: Sprite(engine, level, numSprite, x, y),
	left_key(left_key), right_key(right_key), up_key(up_key), down_key(down_key)
{
	
}

bool  Character::keyPressed(char key)
{
	if (left_key == key)
	{
		return moveAndDraw(-1, 0); 
	}
	else if (right_key == key)
	{
		return moveAndDraw(1, 0); 
	} 
	else if (up_key == key)
	{
		return moveAndDraw(0, -1); 
	}
	else if (down_key == key)
	{
		return moveAndDraw(0, 1); 
	}
	return false; 
}