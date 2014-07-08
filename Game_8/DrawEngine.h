#ifndef DRAWENGINE_H
#define DRAWENGINE_H

class DrawEngine{

public:

	friend class Level; 

	DrawEngine(int width = 30, int height = 20); 

	void drawBackground(void); 
	
	bool createSprite(int num, char key);
	bool createBgSrpite(int num, char key);

	void gotoXY(int x, int y);
	void drawSprite(int num, int x, int y);
	void eraseSprite(int x, int y);

private:
	char **map; 
	
	int width; 
	int height; 


	void turnOffCursor(bool);


	char sprites[16];
	char bgSprites[16];


	
};

#endif