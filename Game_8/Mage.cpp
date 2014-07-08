#include "Mage.h"







Mage::Mage(DrawEngine *engine, const Level *level,
	int numSprite, int x, int y, char left_key ,
	char right_key, char down_key,
	char up_key , char spell_keychar)
	: Character(engine, level, numSprite, x, y)
	, spellKey(spell_keychar)
{
	id = app::MAGE_CLASS_ID; 
}

bool Mage::keyPressed(char key)
{
	bool val = Character::keyPressed(key); 

	if (val == false)
	{
		if (key == spellKey)
		{
			castSpell(); 
			return true; 
		}
	}
	return val; 
}
void Mage::castSpell(void)
{
	Fireball *temp = new Fireball(engine, level, app::SPRITE_FIREBALL,
		(int)pos.x + direction.x, (int)pos.y + direction.y,
		direction.x, direction.y); 

	

	

}