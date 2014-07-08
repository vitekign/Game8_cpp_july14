#ifndef SPRITE_H
#define SPRITE_h

#include "Level.h"
#include "DrawEngine.h"




class Sprite
{
	
protected:

   float x; 
   float y; 
   int sprite; 
   app::vector pos; 
   DrawEngine  *engine; 
   Level const *level; 
   int numLives; 
   app::vector direction; 
   int id; 
  

 public:
	 Sprite(DrawEngine *engine, const Level *level,
		 int numSprite, int x, int y, int numLives = 1);


	 friend class Fireball;

	 virtual void addLives(int num = 1); 
	 virtual bool moveAndDraw(float x, float y);
	 virtual void idleUpdate(void);
	
	 
    void deleteSprite(void);
    bool isAlive(void); 
    bool isMoveLegal(int x, int y);
    void eraseSprite(int x, int y); 
    app::vector getPos(void);
  

    int getX(void); 
    int getY(void); 
};


#endif