#pragma once
#include "Shape.h"

// Preprocessor defines
// #ifdef _DEBUG
//	... Put Debug-specific code Here!
// #endif
#include <vector>
#include <SDL.h>

class Circle :
	public Shape
{
private:
	int m_X;
	int m_Y;
	int m_Radius;

	void CalculateCirclePoints(int SegmentCount);
	std::vector<SDL_Point> m_Points;

public:
	Circle(int X, int Y, int Radius);
	~Circle();

	// Inherited via Shape
	virtual void DrawDebug(SDL_Renderer* pRenderer) override;

	void SetPosition(SDL_Rect* rect);
	void SetPosition(int x, int y);
	Point GetPosition() { return Point{ m_X, m_Y }; }
	int GetRadius() { return m_Radius; }
	int GetRadiusSq() { return m_Radius * m_Radius; }
};

