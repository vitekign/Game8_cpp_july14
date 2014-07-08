#include "Game.h"
#include <conio.h>
#include <iostream>
using namespace std; 

#include "Mage.h"

void Game::run(void)
{
	lastTime = std::chrono::high_resolution_clock::now();
	numFrames = 0;



	level = new Level(&engine); 
	engine.createBgSrpite(app::EMPTY_WALL, ' '); 
	engine.createBgSrpite(app::SOLID_WALL, '*'); 
	engine.createSprite(0, '!'); 
	engine.drawBackground(); 

	engine.createSprite(app::ENEMY_SPRITE, '^');

	player = new Mage(&engine, level, 0, 1, 1); 
	
	level->addCharacter(player);
	level->createEnemies(3); 


	while (key != 'q')
	{
		while (!keyPressed())
		{
			updateTimer(); 
			
		}

		player->keyPressed(key); 

	}
}


bool Game::updateTimer(void)
{
	auto currentTime = std::chrono::high_resolution_clock::now(); 
	if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count() < 30)
	{
		return false; 
	}
	lastTime = std::chrono::high_resolution_clock::now(); 
	numFrames++; 
	level->update(); 

	return true; 
}

bool Game::keyPressed(void)
{
	if (!_kbhit())
		return false; 
	key = _getch(); 
	return true; 
}


