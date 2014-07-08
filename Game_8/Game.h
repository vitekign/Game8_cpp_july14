#ifndef GAME_H
#define GAME_H

#include "DrawEngine.h"


#include <chrono>
#include "Level.h"
class Mage; 


class Game
{
public:
	void run(void); 


private:
	bool updateTimer(void); 
	bool keyPressed(void); 


	char key; 
	int numFrames; 

	std::chrono::high_resolution_clock::time_point lastTime; 

	DrawEngine engine; 
	Level *level; 
	Mage *player; 
};


#endif