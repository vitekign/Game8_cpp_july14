#ifndef CHARACTER_H
#define CHARACTER_H


#include "Sprite.h"



	class Character : public Sprite
	{
	public:

		char left_key;
		char right_key;
		char down_key;
		char up_key;

		Character(DrawEngine *engine, const Level *level,
			int numSprite, int x, int y, char left_key = 's',
			char right_key = 'f', char down_key = 'd',
			char up_key = 'e');

		virtual bool keyPressed(char key);

	};





#endif 