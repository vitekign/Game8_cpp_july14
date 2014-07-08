#ifndef DEF_H
#define DEF_H


namespace app
{
	enum {
		CHARACTER_SPRITE_ID,
		ENEMY_SPRITE_ID,

	};

	enum {
		EMPTY_WALL,
		SOLID_WALL,
		ENEMY_SPRITE, 
		SPRITE_FIREBALL, 

	};


	struct vector{
		float x;
		float y;
	};


	enum{
		CHARACTER_CLASS_ID, 
		ENEMY_CLASS_ID, 
		MAGE_CLASS_ID, 
		FIREBALL_CLASSID,


	};
}


#endif