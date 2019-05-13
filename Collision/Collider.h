#pragma once

#include "Shape.h"

class Collider
{
private:
	Shape* m_pShape;

public:
	bool BoxOverlapsBox(Shape* pBoxA, Shape* pBoxB);
	bool CircleOverlapsCircle(Shape* pCircleA, Shape* pCircleB);

public:
	Collider();
	~Collider();

	Shape* GetShape() { return m_pShape; }
	bool IsOverlapping(Collider* pOther);
	void SetShape(Shape* pShape);
	void DrawDebug(SDL_Renderer* pRenderer) { m_pShape->DrawDebug(pRenderer); }

};

