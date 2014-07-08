#ifndef MAGE_H
#define MAGE_H





#include "Fireball.h"




class Mage : public Character
{
public:
	Mage(DrawEngine *engine, const Level *level,
		int numSprite, int x, int y, char left_key = 's',
		char right_key = 'f', char down_key = 'd',
		char up_key = 'e', char spell_keychar = ' '); 
	
     bool keyPressed(char key);

protected:
	void castSpell(void); 
private: 
	char spellKey; 
};


#endif