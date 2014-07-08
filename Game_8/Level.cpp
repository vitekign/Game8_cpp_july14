#include "Level.h"

#include "DrawEngine.h"

#include "Mage.h"
#include "Enemy.h"


#include <chrono>
#include <random>


#define TEST_DERECTIVE 0 

//Memory Headers
#include <stdio.h>
#include <malloc.h>



Level::Level(DrawEngine  *engine, int width, int height)
	:width(width), height(height)
{
	this->engine = engine; 
	

	this->createMap(); 
	engine->map = map;
	
}



void Level::createMap(void)
{

	map = (char**)calloc(width, sizeof(char*));
	for (int i = 0; i < width; i++){
		map[i] = (char*)calloc(height, sizeof(char*));
	}

	this->populateMap(); 

#if TEST_DERECTIVE
	//Test just created map
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			map[i][j] = 'd';
		}
	}
#endif
}



void Level::populateMap(void)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
	std::default_random_engine e(seed); 

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int random = e() % 100;
			if (i == 0 || j == 0 || i == width - 1 || j == height - 1){
				map[i][j] = app::SOLID_WALL; 
			}
			else {
				if (i < 3 && j < 3){
					map[i][j] = app::EMPTY_WALL; 
				}
				else {
					(random < 80) ? map[i][j] = app::EMPTY_WALL : map[i][j] = app::SOLID_WALL;
				}
			}
		}
	}
}


void Level::createEnemies(int num)
{
	int seed = std::chrono::system_clock::now().time_since_epoch().count(); 
	std::default_random_engine e(seed); 

	while (num != 0)
	{
		int x = ((e() % (this->width - 3)) + 1); 
		int y = ((e() % (this->height - 3)) + 1); 

		if (isSpotEmpty(x, y))
		{
			Enemy *tempEnemy = new Enemy(engine, this, app::ENEMY_SPRITE, x, y); 
			tempEnemy->addGoal(player); 
			npc.push_back(tempEnemy);

			num--; 
		}
	}
}

void Level::update(void)
{
	for (auto i : npc){
		i->idleUpdate();
	}
}

void Level::addCharacter(Mage *c)
{
	player = c; 
}

bool Level::isSpotEmpty(int x, int y)
{
	if (map[x][y] == app::EMPTY_WALL)
		return true; 
	return false; 
}