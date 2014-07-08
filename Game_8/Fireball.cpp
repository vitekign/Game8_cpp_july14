#include "Fireball.h"




Fireball::Fireball(DrawEngine *engine, const Level *level,
	int numSprite, int x, int y, int numLives,
	float xDir, float yDir)
	: Sprite(engine, level, numSprite, x, y, numLives)
{
	direction.x = xDir;
	direction.y = yDir;

	id = app::FIREBALL_CLASSID;
}





void Fireball::idleUpdate(void)
{
	if (moveAndDraw(direction.x, direction.y))
	{
		for (auto i : level->npc)
		{
			if (i->id != id && (int)i->getX() == (int)pos.x &&
				(int)i->getY() == (int)pos.y)
			{
				i->addLives(-1);
				addLives(-1);

			
				
			}
		}
	}
	else
		addLives(-1); 
}
