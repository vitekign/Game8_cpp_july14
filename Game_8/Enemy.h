#ifndef ENEMY_H
#define ENEMY_H


#include "Mage.h"



class Enemy : public Sprite
{

public:
	friend class Fireball; 

	Enemy(DrawEngine *engine, const Level *level,
		int numSprite, int x, int y); 
	
	virtual void  idleUpdate(void); 
	virtual bool  moveAndDraw(float x, float y);
	
	void addGoal(Mage *g); 
	void simulateAI(void); 


private:
	Mage *goal; 
};

#endif