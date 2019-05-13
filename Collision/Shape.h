#pragma once

#include "GameStd.h"

struct SDL_Renderer;

class Shape
{
private:

protected:


	EShapeType m_Type;

public:
	Shape();
	virtual ~Shape();

	virtual void DrawDebug(SDL_Renderer* pRenderer) = 0;

	EShapeType GetType() const { return m_Type; }
};

