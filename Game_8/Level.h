#ifndef LEVEL_H
#define LEVEL_H

#include <list>




#include "definitions.h"

class Mage; 



class Level


{
public:

	friend class DrawEngine;
	friend class Sprite; 

	Level(DrawEngine *engine, int width = 30, int height = 20); 

	void createEnemies(int num);
	void update(void);
	void addCharacter(Mage *c);

	bool isSpotEmpty(int x, int y); 

	std::list<Sprite*> npc;


private:
	void createMap(void); 
	void populateMap(void); 
	int width, height; 
	
	DrawEngine *engine; 
	Mage *player; 

	

	



protected:

	char **map; 
};

#endif