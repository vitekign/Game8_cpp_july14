#include "Enemy.h"
#include <random>
#include <chrono>






Enemy::Enemy(DrawEngine *engine, const Level *level,
	int numSprite, int x, int y)
	:Sprite(engine, level, numSprite, x, y)
{
	id = app::ENEMY_CLASS_ID; 

}
void  Enemy::idleUpdate(void)
{
	if (goal)
		simulateAI();
}


void Enemy::addGoal(Mage *g)
{
	if (g)
		goal = g; 
}



void Enemy::simulateAI(void)
{
	app::vector dist;
	dist = goal->getPos(); 
	dist.x -= pos.x; 
	dist.y -= pos.y; 

	float mag = sqrt(dist.x * dist.x + dist.y * dist.y); 
	app::vector unit; 
	unit.x = dist.x / (mag * 20); 
	unit.y = dist.y / (mag * 20); 

	if (!moveAndDraw(unit.x, unit.y))
	{
		float seed = std::chrono::system_clock::now().time_since_epoch().count(); 
		std::default_random_engine e(seed); 

		while (!moveAndDraw(rand() % 3 - 1, rand() % 3 - 1))
		{
			
		}
	}
}


bool  Enemy::moveAndDraw(float x, float y)
{
	app::vector temp; 
	temp.x = pos.x + x; 
	temp.y = pos.y + y; 

	if (isMoveLegal(int(temp.x), int(temp.y)))
	{
		for (auto i : level->npc){
			if (i != this && (i->getX() == (int)temp.x) && (i->getY() == (int)temp.y))
				return false; 
		}

		Sprite::eraseSprite(int(pos.x), int(pos.y)); 
		Sprite::moveAndDraw(x, y); 
		
		return true; 
	}

	return false; 
}