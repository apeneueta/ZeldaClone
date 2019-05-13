#include "Box.h"

#include "SDL.h"

Box::Box(int x, int y, int width, int height)
	: m_x(x) // Member initializer list (Constructors Only)
	, m_y(y)
	, m_width(width)
	, m_height(height)
{
	// When we create a box, it will remember that for later
	m_Type = EShapeType::Box;
}

Box::Box(SDL_Rect* rect)
{
	m_x = rect->x;
	m_y = rect->y;
	m_width = rect->w;
	m_height = rect->h;
	m_Type = EShapeType::Box;
}


Box::~Box()
{
}

void Box::DrawDebug(SDL_Renderer * pRenderer)
{
	// Make a rect centered around x and y
	SDL_Rect DrawRect{ m_x - (m_width / 2), m_y - (m_height / 2), m_width, m_height };

	SDL_SetRenderDrawColor(pRenderer, 255, 0, 255, 255);
	SDL_RenderDrawRect(pRenderer, &DrawRect);
}

void Box::SetPosition(SDL_Rect * rect)
{
	// These numbers only work with this character
	m_x = rect->x + (rect->w / 2);
	m_y = rect->y + (rect->h / 2) + 5;
	m_width = rect->w - 15;
	m_height = rect->h - 10;
}

Point Box::GetMin()
{
	Point min;
	min.x = m_x - (m_width / 2);
	min.y = m_y - (m_height / 2);
	return min;
}

Point Box::GetMax()
{
	Point max;
	max.x = m_x + (m_width / 2);
	max.y = m_y + (m_height / 2);
	return max;
}
