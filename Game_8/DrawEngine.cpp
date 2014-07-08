#include "DrawEngine.h"
#include <Windows.h>

#include <iostream>
using namespace std; 


DrawEngine::DrawEngine(int width, int height)
	:width(width), height(height)
{
	
	turnOffCursor(false); 
	
}

void DrawEngine::drawBackground(void)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			gotoXY(i, j);
			cout << bgSprites[map[i][j]]; 
		}
	}
}

void DrawEngine::turnOffCursor(bool sw)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE); 

	CONSOLE_CURSOR_INFO info; 
	info.bVisible = sw; 
	info.dwSize = 1; 

	SetConsoleCursorInfo(handle, &info); 
}

void DrawEngine::gotoXY(int x, int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos; 
	pos.X = x; 
	pos.Y = y; 

	SetConsoleCursorPosition(handle, pos); 
}

void DrawEngine::drawSprite(int num, int x, int y)
{
	gotoXY(x, y); 
	cout << sprites[num]; 
}

void DrawEngine::eraseSprite(int x, int y)
{
	gotoXY(x, y); 
	cout << ' '; 
}

bool DrawEngine::createSprite(int num, char key)
{
	if (num >= 0 && num < 16) {
		sprites[num] = key;
		return true;
	}
	return false;
}

bool DrawEngine::createBgSrpite(int num, char key)
{
	if (num >= 0 && num < 16){
		bgSprites[num] = key;
		return true;
	}
	return false;
}