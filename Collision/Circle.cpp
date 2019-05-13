#include "Circle.h"


void Circle::CalculateCirclePoints(int SegmentCount)
{
	float DegreesBetweenPoints = 360.0f / SegmentCount;
	float RadiansBetweenPoints = DegreesBetweenPoints * (M_PI / 180.0f);

	for (int PointIndex = 0; PointIndex <= SegmentCount; ++PointIndex)
	{
		SDL_Point Point;

		Point.x = m_X + cosf(RadiansBetweenPoints * PointIndex) *
			m_Radius;
		Point.y = m_Y + sinf(RadiansBetweenPoints * PointIndex) *
			m_Radius;

		m_Points.push_back(Point);
	}
}

Circle::Circle(int X, int Y, int Radius)
	: m_Radius(Radius)
{
	m_X = X;
	m_Y = Y;

	m_Type = EShapeType::Circle;

	CalculateCirclePoints(CIRCLE_SEGMENTS);
}


Circle::~Circle()
{
}

void Circle::DrawDebug(SDL_Renderer * pRenderer)
{
	SDL_SetRenderDrawColor(pRenderer, 255, 0, 255, 255);
	SDL_RenderDrawLines(pRenderer, &m_Points[0], m_Points.size());
}

void Circle::SetPosition(SDL_Rect * rect)
{
	m_Points.clear();
	m_X = rect->x;// +(rect->w / 2);
	m_Y = rect->y;// +(rect->h / 2) + 5;
	CalculateCirclePoints(CIRCLE_SEGMENTS);
}

void Circle::SetPosition(int x, int y)
{
	m_Points.clear();
	m_X = x;
	m_Y = y;
	CalculateCirclePoints(CIRCLE_SEGMENTS);
}
