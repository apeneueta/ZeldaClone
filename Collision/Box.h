#pragma once
#include "Shape.h"
#include <SDL.h>

struct SDL_Renderer;

class Box :
	public Shape
{
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	Box(int x, int y, int width, int height);
	Box(SDL_Rect* rect);
	~Box();

	void DrawDebug(SDL_Renderer* pRenderer) override;

	void SetPosition(SDL_Rect* rect);
	Point GetMin();
	Point GetMax();

};

