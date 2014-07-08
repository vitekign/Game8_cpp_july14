#ifndef FIREBALL_H
#define FIREBALL_H


#include "Character.h"



class Fireball : public Sprite
{
public:

	Fireball(DrawEngine *engine, const Level *level,
		int numSprite, int x, int y, int numLives = 1,
		float xDir = 0, float yDir = 0); 
	
	void idleUpdate(void); 

};



#endif